# 🧮 Simple Calculator using GTK 

This simple calculator application is built using GTK (GIMP Toolkit) in C, providing basic arithmetic functionalities such as addition, subtraction, multiplication, and division. 🚀

## ✨ Features

- Arithmetic Operations: ➕ Addition, ➖ Subtraction, ✖️ Multiplication, ➗ Division.
- Clearing Input: 🔴 Clear input field and reset calculations.
- Decimal Point: Allow decimal input for floating-point numbers.

## 🛠️ Requirements

- **GTK Library:** Ensure that the GTK library is installed to compile and run this program.
- **C Compiler:** Use a C compiler like GCC to build the application.

## 💡 How to Use

1. **Compile the Code:**
   - Use a C compiler to compile the code. For example:
     ```
     gcc main.c -o calculator `pkg-config --cflags --libs gtk+-3.0`
     ```

2. **Run the Application:**
   - Execute the compiled binary to launch the calculator.

   ``` bash
    ./calculator
    ```

3. **Calculator Interface:**
   - The calculator window will display the numeric buttons (0-9), arithmetic operators (➕, ➖, ✖️, ➗), decimal point (.), and the equals (=) button.
   - Click on the buttons to perform calculations.

## 🤝 Contributions

Contributions are welcome! If you'd like to enhance or fix any part of this calculator, feel free to submit a pull request.
