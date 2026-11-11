# Libft

*This project has been created as part of the 42 curriculum by
moboulah.*

## Description

**libft** is a custom C library built as part of the 42 curriculum. Its
goal is to recreate a useful selection of standard C library functions
and provide additional utilities for working with strings, memory, and
linked lists.

Implementing these functions helps develop a deeper understanding of
pointers, memory allocation, byte manipulation, string handling, type
conversions, and linked data structures. The resulting `libft.a` static
library can be reused in later C projects.

## Library contents

The exact set of functions depends on the files included in this
repository. The library is organized around these groups:

### Character checks and conversions

-   `ft_isalpha`, `ft_isdigit`, `ft_isalnum`
-   `ft_isascii`, `ft_isprint`
-   `ft_toupper`, `ft_tolower`

These functions classify characters or convert between lowercase and
uppercase letters.

### String utilities

-   `ft_strlen`, `ft_strchr`, `ft_strrchr`
-   `ft_strncmp`, `ft_strnstr`
-   `ft_strlcpy`, `ft_strlcat`
-   `ft_strdup`, `ft_substr`, `ft_strjoin`
-   `ft_strtrim`, `ft_split`
-   `ft_itoa`, `ft_strmapi`, `ft_striteri`

These functions measure, search, compare, copy, join, trim, split, or
transform strings. Allocation-returning functions provide dynamically
allocated results that the caller must free when appropriate.

### Memory utilities

-   `ft_memset`, `ft_bzero`
-   `ft_memcpy`, `ft_memmove`
-   `ft_memchr`, `ft_memcmp`
-   `ft_calloc`

These functions operate on memory as bytes, including operations that
are not limited to null-terminated strings.

### Numeric conversion and output

-   `ft_atoi` converts the initial portion of a string to an integer.
-   `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
    write characters, strings, lines, or integers to a file descriptor.

### Linked-list utilities

This part uses the `t_list` structure, which contains a `content`
pointer and a `next` pointer. Typical list operations include: -
`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back` - `ft_lstsize`,
`ft_lstlast` - `ft_lstdelone`, `ft_lstclear` - `ft_lstiter`, `ft_lstmap`

These helpers create, traverse, modify, and free singly linked lists.
The deletion callbacks determine how list content is released. Check the
source files and `libft.h` for the authoritative list of functions
implemented in this repository.

## Instructions

### Requirements

-   A C compiler such as `cc` or `gcc`
-   `make`
-   A Unix-like environment

### Build the library

From the repository root, run:

``` sh
make
```

This should compile the source files and create the static library
`libft.a` (depending on the targets defined in the Makefile).

Common Makefile targets, if provided by this repository, may include:

``` sh
make clean
make fclean
make re
```

-   `clean` removes object files.
-   `fclean` removes object files and the compiled library.
-   `re` performs a full rebuild.

### Use the library in a C project

Include the header in your source file:

``` c
#include "libft.h"
```

Compile your source file and link against the library. For example, if
`main.c` is in the repository root:

``` sh
cc main.c -L. -lft -I. -o program
```

Then run:

``` sh
./program
```

Only call functions that are implemented in the version of the library
you have built. For functions that allocate memory, check for allocation
failure and free the returned memory when it is no longer needed.

## Resources

The following references were consulted while learning and implementing
the library:

-   [cppreference ---
    Pointers](https://en.cppreference.com/w/c/language/pointer) ---
    pointer types, null pointers, and pointer declarations.
-   [cppreference --- Implicit
    conversions](https://en.cppreference.com/w/c/language/conversion)
    --- integer promotions and arithmetic conversions.
-   [GNU C Manual --- Signed and unsigned
    types](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Signed-and-Unsigned-Types.html)
    --- signedness and integer ranges.
-   [C11 draft (N1570)](https://oifans.cn/docs/c11/n1570.html) ---
    reference for C language rules and standard-library behavior.
-   [C89 draft
    reference](https://bohr.wlu.ca/hfan/cp264/references/c89-draft.html)
    --- older C language specification reference.
-   [GNU Make Manual --- Pattern
    rules](https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html)
    --- pattern rules and automatic variables used in Makefiles.
-   [GeeksforGeeks --- Difference between `malloc()` and
    `calloc()`](https://www.geeksforgeeks.org/c/difference-between-malloc-and-calloc-with-examples/)
    --- introductory comparison of dynamic allocation functions.
-   [Stack Overflow --- What is `size_t` in
    C?](https://stackoverflow.com/questions/2550774/what-is-size-t-in-c)
    --- discussion of the purpose and properties of `size_t`.
-   [Stack Overflow --- Why use `unsigned char` for binary
    data?](https://stackoverflow.com/questions/13642381/c-c-why-to-use-unsigned-char-for-binary-data)
    --- byte-level operations and unsigned character types.
-   [Stack Overflow --- How do function pointers work in
    C?](https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work)
    --- function-pointer syntax and usage.
-   [Stack Overflow discussions on `SIZE_MAX` and
    `calloc()`](https://news.ycombinator.com/item?id=36779292) ---
    supplementary discussion of allocation limits and `size_t`.
