import tkinter as tk
import os
from tkinter import PhotoImage

BASE_DIR = os.path.join(os.getcwd(), "src")


def theme_toggle():
    global is_dark
    is_dark = not is_dark
    if is_dark:
        apply_dark_theme()
    else:
        apply_light_theme()

def apply_dark_theme():
    root.config(bg='#333333')
    display.config(bg='#222222', fg='white', font=('Arial', 20))
    for button in buttons.values():
        button.config(bg='#666666', fg='black', width=5, height=2, font=('Arial', 18))  

def apply_light_theme():
    root.config(bg='white')
    display.config(bg='white', fg='black', font=('Arial', 20))
    for button in buttons.values():
        button.config(bg='lightgray', fg='black', width=5, height=2, font=('Arial', 18)) 

def add_to_display(value):
    current = display.get()
    if current == 'Error':
        current = ''
    display.delete(0, tk.END)
    display.insert(tk.END, current + value)

def clear_display():
    display.delete(0, tk.END)

def calculate():
    try:
        result = eval(display.get())
        display.delete(0, tk.END)
        display.insert(tk.END, str(result))
    except ZeroDivisionError:
        display.delete(0, tk.END)
        display.insert(0, "Can't divide by Zero")
    except:
        display.delete(0, tk.END)
        display.insert(tk.END, 'Error')

root = tk.Tk()
window_icon = PhotoImage(file=os.path.join(BASE_DIR, "maths.png"))
root.iconphoto(False, window_icon)
root.title("Calculator")
root.resizable(height=0, width=0)

is_dark = False

display = tk.Entry(root, width=25, font=('Arial', 24), justify='right') 
display.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

buttons = {}

def create_button(text, command, row, column):
    button = tk.Button(root, text=text, command=command, width=5, height=2, bd=0, relief='flat', font=('Arial', 18)) 
    button.grid(row=row, column=column, padx=5, pady=5)
    buttons[text] = button

create_button('7', lambda: add_to_display('7'), 1, 0)
create_button('8', lambda: add_to_display('8'), 1, 1)
create_button('9', lambda: add_to_display('9'), 1, 2)
create_button('/', lambda: add_to_display('/'), 1, 3)
create_button('4', lambda: add_to_display('4'), 2, 0)
create_button('5', lambda: add_to_display('5'), 2, 1)
create_button('6', lambda: add_to_display('6'), 2, 2)
create_button('*', lambda: add_to_display('*'), 2, 3)
create_button('1', lambda: add_to_display('1'), 3, 0)
create_button('2', lambda: add_to_display('2'), 3, 1)
create_button('3', lambda: add_to_display('3'), 3, 2)
create_button('-', lambda: add_to_display('-'), 3, 3)
create_button('0', lambda: add_to_display('0'), 4, 0)
create_button('.', lambda: add_to_display('.'), 4, 1)
create_button('=', lambda: calculate(), 4, 2)
create_button('+', lambda: add_to_display('+'), 4, 3)
create_button('AC', lambda: clear_display(), 5, 0)
create_button('Theme', lambda: theme_toggle(), 5, 3)

apply_light_theme()
root.mainloop()
