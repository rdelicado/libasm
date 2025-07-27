# Libasm

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Assembly](https://img.shields.io/badge/Assembler-NASM-green.svg)](https://www.nasm.us/)

## 📖 Overview

**Libasm** is a small library implementing common C standard functions in x86_64 Assembly (NASM). This project demonstrates low-level system call usage, memory manipulation, and string routines written from scratch. It is a core exercise in systems programming and assembly language mastery.

## 🔍 Implemented Functions

The following functions, originally from `libc`, are reimplemented in assembly:

- `ft_strlen`   — Calculate the length of a null-terminated string
- `ft_strcmp`   — Compare two strings lexicographically
- `ft_strcpy`   — Copy a string including its terminating null byte
- `ft_read`     — Read up to `count` bytes from a file descriptor
- `ft_write`    — Write up to `count` bytes to a file descriptor
- `ft_strdup`   — Duplicate a string by allocating memory

Function prototypes are declared in `includes/libasm.h`.

## 🗂️ Project Structure

```
libasm/
├── Makefile              # Build and test rules
├── includes/
│   └── libasm.h          # Public API headers
├── src/                  # Assembly source files (.s)
│   ├── ft_strlen.s
│   ├── ft_strcmp.s
│   ├── ft_strcpy.s
│   ├── ft_read.s
│   ├── ft_write.s
│   └── ft_strdup.s
├── unitest/              # C-based unit tests
│   ├── main.c
│   ├── test_strlen.c
│   ├── test_strcmp.c
│   ├── test_strcpy.c
│   ├── test_read.c
│   ├── test_write.c
│   ├── test_strdup.c
│   └── utils.c           # Test helpers
└── obj/                  # Compiled object files
```

## 🚀 Getting Started

### Prerequisites

- GNU Make
- NASM (Netwide Assembler)
- GCC (with 64-bit support)

### Building the Library

```sh
make all        # Assemble and archive libasm.a
```

### Running Tests

```sh
make test       # Build and run unit tests
```

All tests must pass before submitting your code.

### Cleaning Up

```sh
make clean      # Remove object files and test binaries
make fclean     # Remove archive libasm.a as well
```

## 🛠️ Usage in Your Project

Include the header and link against `libasm.a`:

```c
#include "libasm.h"

int main(void) {
    const char *s = "Hello, World!";
    size_t len = ft_strlen(s);
    ft_write(1, s, len);
    return 0;
}
```

```sh
gcc -Iincludes -L. -lasm your_program.c -o your_program
```

## 📚 Contributing

- Follow the 42 Norm for coding style.
- Ensure all new functions have accompanying tests.
- Submit pull requests for review with clear descriptions.

## 👤 Author

**Rubén Delicado** — [@rdelicado](https://github.com/rdelicado)

## 📜 License

This project is part of the 42 School curriculum and is intended for educational purposes. All code follows academic integrity guidelines.