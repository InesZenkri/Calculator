#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

GtkWidget *entry;

#define SIZE 10

char input_buffer[100] = {0};
char output_buffer[100] = {0};

bool clear_buffer = false;
bool add = false;
bool mul = false;
bool divv = false;
bool sub = false;

float result = 0.0;
static float num[SIZE];
int count = 0;

static void calculate(GtkButton *button, gpointer data) {
    const gchar *text = gtk_button_get_label(button);

    if ((strcmp("+", text) == 0) || (strcmp("-", text) == 0) || (strcmp("/", text) == 0) || (strcmp("x", text) == 0) || (strcmp("=", text) == 0)) {

        num[count] = atof(input_buffer);
        count++;
        clear_buffer = true;

        if (strcmp("+", text) == 0) {
            add = true;
        }
        if (strcmp("-", text) == 0) {
            sub = true;
        }
        if (strcmp("/", text) == 0) {
            divv = true;
        }
        if (strcmp("x", text) == 0) {
            mul = true;
        }
    }

    if (strcmp("=", text) == 0) {


        add = false;
        mul = false;
        divv = false;
        sub = false;

        gtk_entry_set_text(GTK_ENTRY(entry), "");
        sprintf(output_buffer, "%.3f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), output_buffer);
        result = 0.0;
    } else {
        if (clear_buffer) {
            memset(input_buffer, 0, strlen(input_buffer));
            clear_buffer = false;
        }
        else 
            strncat(input_buffer, text, 1);
    

        strncat(output_buffer, text, 1);
        gtk_entry_set_text(GTK_ENTRY(entry), output_buffer);
    }

    if (strcmp("C", text) == 0) {
        gtk_entry_set_text(GTK_ENTRY(entry), "");
        memset(input_buffer, 0, strlen(input_buffer));
        memset(output_buffer, 0, strlen(output_buffer));

        count = 0;
        int x = sizeof(num) / sizeof(num[0]);

        for (int i = 0; i < x; i++) {
            num[i] = 0;
        }

        add = false;
        mul = false;
        divv = false;
        sub = false;
    }
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button[17];

    window = gtk_application_window_new(app);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    const gchar *button_labels[17] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "+", "-", "x", "/", "AC", "="};

    for (int i = 0; i < 17; i++) {
        button[i] = gtk_button_new_with_label(button_labels[i]);
        gtk_grid_attach(GTK_GRID(grid), button[i], i % 4, (i / 4) + 1, 1, 1);
        g_signal_connect(button[i], "clicked", G_CALLBACK(calculate), NULL);
    }

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;

    gtk_init(&argc, &argv);

    int status;
    app = gtk_application_new("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
