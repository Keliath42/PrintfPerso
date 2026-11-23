*This activity has been created as part of the 42 curriculum by kpuythor.*

# Description

**ft_printf** is a project from the 42 curriculum that consists of recreating the standard C library function `printf()`.

The goal is to understand how variadic functions work in C, how formatted output is processed, and how different data types can be converted into printable characters.

The function takes a format string and a variable number of arguments, processes each format specifier, writes the corresponding output to standard output, and returns the total number of characters printed.

The project produces a static library named `libftprintf.a`, which can be linked to other C programs.

# Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a percent sign |

# Instructions

## Compilation

Once you cloned the repository on your PC, navigate to the project directory. You can then compile the library using :

```bash
make
```

or :

```Bash
make all
```

This creates `libftprintf.a`.

**Makefile rules**

| Command | Description |
|---------|-------------|
| `make` | Compiles the library (with -Wall -Werror -Wextra -fPIC flags) |
| `make clean` | Removes object files from |
| `make fclean` | Removes object files and the library |
| `make re` | Recompiles the entire library |

## Usage

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library :

```Bash
cc main.c libftprintf.a -o program
```

Run the executable :

```Bash
./program
```

# Algorithm and Data Structure

## 1. Variadic Arguments

Unlike regular functions, `ft_printf` accepts a variable number of arguments. This is implemented using the macros from `<stdarg.h>`:

- `va_list` stores the state required to access the arguments.
- `va_start` initializes argument processing.
- `va_arg` retrieves each argument using its expected type.
- `va_end` finishes argument processing.

Arguments are retrieved as their corresponding conversion specifiers are encountered.

## 2. Format String Parsing

The main algorithm scans the format string from left to right:

1. Print ordinary characters directly.
2. When `%` is encountered, inspect the following conversion specifier.
3. Dispatch the conversion to the relevant helper function.
4. Accumulate the number of characters written and return that total.

Sequential parsing is a natural fit because the format string and its arguments are consumed in order. The work is proportional to the input format length plus the number of output characters produced.

## 3. Conversion Algorithms

**Characters and strings:** Characters can be written directly. Strings are traversed until their terminating `\0` character.

**Signed and unsigned integers:** Decimal digits are determined using division and modulo by 10. Negative signed values require handling the minus sign and the magnitude safely.

**Hexadecimal values:** The same digit-extraction idea is applied in base 16, using `0123456789abcdef` for `%x` and `0123456789ABCDEF` for `%X`.

**Pointers:** A pointer value is rendered in hexadecimal with the `0x` prefix, using an integer type suitable for holding its representation.

## 4. Data Structures

No elaborate data structure is necessary. The implementation primarily relies on:

- `va_list` for processing variable arguments.
- Character pointers and indices for traversing strings.
- Integer values for digit extraction and conversion.
- A counter for the total number of printed characters.

This minimizes additional storage because formatted output does not need to be assembled into a separate buffer first.

## 5. Technical Choices

- **Modularity:** Separate helpers handle different conversions, making the implementation easier to test and maintain.
- **Direct output:** Characters are written to standard output using `write()` rather than building one large formatted string.
- **Code reuse:** Relevant existing `libft` functions are reused where appropriate.
- **Static library:** `libftprintf.a` can be linked into other C programs.

# Resources

## Documentation

- [printf(3) — Linux manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) — Linux manual](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [write(2) — Linux manual](https://man7.org/linux/man-pages/man2/write.2.html)
- [GNU C Library manual](https://www.gnu.org/software/libc/manual/)

## AI Usage

AI was used as a learning and debugging assistant throughout the project.

Its role was limited to explaining programming concepts (such as variadic arguments), asking guiding questions and helping analyze errors or unexpected behaviors.

All functions were implemented and debugged manually, with an emphasis on understanding the underlying logic rather than receiving ready-made solutions.

AI was also used to help write this README.

## Testing

The project was tested against expected `printf()` behavior for supported conversions, edge cases, and mixed format strings. Additional checks used Tripouille's ft_printf tester.
