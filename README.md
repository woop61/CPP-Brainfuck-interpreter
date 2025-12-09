[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

# Optimized Brainfuck Interpreter

A lightweight, optimized interpreter for the [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) esoteric programming language, written in C++20.

This project was developed as part of a **Compilation Theory** course to explore lexical analysis and interpreter architecture.
It features an optimization pass that compresses sequences of identical instructions (Run-Length Encoding) to improve execution speed.

## 🚀 Features

* **Instruction Optimization:** The preprocessor groups repeated commands (e.g., `+++++`, `>>>>>`) into single operations, significantly reducing the instruction fetch overhead.
* **Loop Pre-computation:** Jump targets for loops (`[` and `]`) are calculated during preprocessing, avoiding runtime scans.
* **Robust Error Handling:** Detects and reports syntax errors such as mismatched brackets or unclosed loops with specific position indicators.
* **Memory Management:** Implements a standard 30,000-cell tape with wrapping pointers.

* 🧠 Technical Details
Optimization Strategy
The interpreter uses a preprocessing step before execution. Instead of executing characters directly, it converts the raw source string into a vector of Operation structs.

Raw: +++++ (5 iterations of the interpreter loop)

Optimized: Operation { type: '+', operand: 5 } (1 iteration)

This mimics the tokenization phase in compiler design, effectively transforming the source code into an intermediate representation (IR) for faster execution.

## 🛠️ Installation & Build

Ensure you have a C++ compiler supporting C++20 (e.g., `g++`) and `make` installed.

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/woop61/CPP-Brainfuck-interpreter](https://github.com/woop61/CPP-Brainfuck-interpreter)
    cd CPP-Brainfuck-interpreter
    ```

2.  **Build the project:**
    Use the provided Makefile to compile the source code.
    ```bash
    make
    ```

3.  **Clean build files (Optional):**
    ```bash
    make clean
    ```

## 💻 Usage

The interpreter reads Brainfuck source code directly from standard input (`stdin`). You can pipe a file into it or type interactively.

# Run the included sample script
./BF_Interpreter < hello.bf

**Running a file:**
```bash
./BF_Interpreter < script.bf

