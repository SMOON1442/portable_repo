# ft_printf
*This project has been created as part of the 42 curriculum by moboulah.*

## Description

`ft_printf` is a C library that reimplements the core behavior of the standard C
`printf()` function. Its purpose is to format and print data to the standard
output while providing practice with variadic functions, formatted output,
pointer handling, integer bases, and low-level memory and calling-convention
concepts.

The library provides the following function:

```c
int ft_printf(const char *s, ...);
```

It supports these conversions:

| Conversion | Behavior |
| --- | --- |
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints a literal percent sign. |

The implementation does not reproduce the internal buffering system of the
original `printf()`. It writes output using the authorized `write()` function
and returns the number of characters printed, subject to the behavior required
by the project.

## Instructions

### Requirements

- A C compiler such as `cc` or `gcc`.
- `make`.
- `ar`, to create the static library. 

### Compilation

Run the following command at the root of the repository:

```sh
make
```

This builds the static library:

```text
libftprintf.a
```

The Makefile also provides the required targets:

```sh
make all
make clean
make fclean
make re
```

- `all`: builds the library.
- `clean`: removes object files.
- `fclean`: removes object files and the generated library.
- `re`: performs a full rebuild.

### Using the library

Include the project header in your source file:

```c
#include "ft_printf.h"
```

Compile your program with the library. For example:

```sh
cc main.c -L. -lftprintf
```


## Algorithm and Data Structure

### Format-string parsing

The implementation uses a sequential, pointer-based parsing algorithm. The
`const char *s` pointer traverses the format string from left to right until
the terminating null character is reached.

- If the current character is not `%`, it is printed directly using
  `ft_putchar()`, and the pointer advances by one character.
- If the current character is `%`, `print_arg()` is called to identify the
  conversion and print the corresponding argument. The pointer then advances
  by two characters to move past the conversion specifier.

This allows the format string to be processed in a single pass without
creating an intermediate formatted-output buffer.

### Variadic argument handling

`ft_printf()` declares a `va_list` named `args` and initializes it with
`va_start(args, s)`. When a conversion is encountered, it passes the address
of this list to `print_arg()`.

`print_arg()` uses `va_arg()` to retrieve the next argument with the type
required by the conversion. Passing the address of `args` allows the helper
function to advance the same variadic argument-list state as it processes
each conversion. Once parsing is complete, `ft_printf()` calls `va_end()`.

The format string determines which type must be retrieved for each argument;
the ellipsis itself does not provide an argument count or runtime type
information.

### Character counter and helper functions

An integer variable named `count` keeps track of the number of characters
printed. Each output function returns the number of characters it prints, and
that result is added to `count`. The final value is returned by `ft_printf()`.

Each conversion is delegated to a dedicated helper function. For example,
`ft_putchar()` handles characters, `ft_putstr()` handles strings,
`ft_putnbr()` handles signed decimal integers, and the hexadecimal and pointer
printing functions handle their respective representations.

### Data structures and design choices

The implementation does not use complex data structures such as arrays,
linked lists, or dynamically allocated output buffers. It relies on:

- A pointer (`s`) to traverse the format string.
- A `va_list` (`args`) to keep track of variadic arguments.
- Integer counters (`count`) to track the number of characters printed.
- Dedicated helper functions to handle individual conversions.

This design is suitable because the format string can be parsed and printed
directly in one pass. It avoids storing the complete formatted output in
memory, keeps argument retrieval tied to the corresponding conversion, and
separates the main parsing logic from the individual printing operations.

## Resources

The following references were used to study variadic functions, memory layout,
calling conventions, and the Application Binary Interface (ABI):

- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic):
  documentation for `va_list`, `va_start`, `va_arg`, `va_copy`, and `va_end`.
- [Scaler — Memory Layout in C](https://www.scaler.com/topics/c/memory-layout-in-c/):
  an overview of C program memory layout and the stack.
- [Wikipedia — x86 calling conventions](https://en.wikipedia.org/wiki/X86_calling_conventions):
  an overview of how function arguments, registers, and stack cleanup are
  handled by calling conventions.
- [Stack Overflow — What is an ABI?](https://stackoverflow.com/questions/2171177/what-is-an-application-binary-interface-abi):
  an introduction to the Application Binary Interface and the rules that allow
  compiled code to interact.

### Use of AI

AI assistance was used as a learning and reference tool during the project.
It helped explain variadic functions and the `va_list` family of macros, the
role of calling conventions and the ABI, how function arguments may be passed
through registers or the stack, and the C program memory layout.
