# printf

## Synopsis

A re-creation of the printf function in C

## Prep material

[Secrets of printf](http://www.cypress.com/file/54761/download)

[man (3) printf](https://linux.die.net/man/3/printf)

## Requirements for this project

- Code must comply with the [Betty](https://github.com/holbertonschool/Betty) style and document checks.
- Compile code using flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic`, `-Wno-format`
- Cannot use global variables.
- Restricted to no more than 5 functions per file.
- Function prototypes should be included in header file `holberton.h`
- Header files should be include guarded.
- Authorized functions and macros:
  - `write` (`man 2 write`)
  - `malloc` (`man 3 malloc`)
  - `free` (`man 3 free`)
  - `va_start` (`man 3 va_start`)
  - `va_end` (`man 3 va_end`)
  - `va_copy` (`man 3 va_copy`)
  - `va_arg` (`man 3 va_arg`)

## Code Example

![Alt text](https://cloud.githubusercontent.com/assets/6486822/24182816/8af4a364-0e81-11e7-9fe1-9299b94e0a15.png)
This piece of code shows that we have array of structs with specifiers and function pointers to the functions that copy argument related to specifier into the buffer.
At the end we print content of the buffer that holds output according to a format.

## Motivation

To learn how function pointers, variatic functions, pointers, structs etc. works.

## Installation

Clone the project repo and compile it. It was compiled using this command: gcc -Wall -Wextra -Werror -pedantic -Wno-format main.c _putchar.c cpy_string.c cpy_int.c _printf.c cpy_special.c -o printf
main.c is c program with test cases (look at example bellow).

## Files Reference

- holberton.h - header file
  - contains prototypes of all the functions described bellow
  - definition of a struct used to define specifiers and functions that make a copy into the buffer
  
- _printf.c 
  - _printf - uses array of structs to find specifier and functions that would copy argument related to that specifier into the buffer and then prints out the content of the buffer at the end and returns the length of printed string.
  - buffer_full - once buffer gets full it prints the content of that buffer to standard output and resets it to zero and returns index to 0
  - clear_buffer - resets buffer to zeros
  
- cpy_int.c
  - cpy_int - copies argument of type int into the buffer
  - cpy_ui - copies argument of type unsigned int into the buffer
  - cpy_hex - copies argument of type unsigned int converted to lower case hexadecimal into the buffer
  - cpy_HEX - copies argument of type unsigned int converted to upper case hexadecimal into the buffer
  - cpy_oct - copies argument of type unsigned int converted to octal into the buffer

- cpy_string.c
  - cpy_string - copies argument of type char* (pointer to string) into the buffer
  - cpy_char - copies argument of type char into the buffer
  - cpy_rev - copies argument of type char* (pointer to string) in reverse into the buffer
  - cpy_bin - copies argument of type unsigned int converted to binary into the buffer
  - cpy_rot13 - copies argument of type char* (pointer to string) converted to rot13 into the buffer

- cpy_special.c
  - cpy_special - prints the string where non printable characters (0 < ASCII value < 32 or >= 127) printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
  
- _putchar.c
  - _putchar - prints a character passed as argument to standard output
  - _strlen - returns length of a string passed to it as argument
  - _strprint - prints a string passed to it as argument to standard output
  - _strcpy - copies one string into another
  
## Tests

Example of a test program comparing system printf comapring to this project:
![Alt text](https://cloud.githubusercontent.com/assets/6486822/24183348/2705264a-0e85-11e7-89d4-abef61f66cb4.png)

The output of the above test case:
![Alt text](https://cloud.githubusercontent.com/assets/6486822/24183349/27060b64-0e85-11e7-88e5-e541258b3cbc.png)

## Contributors

[Julija Lee](https://twitter.com/LeeJulija) and [Galina Veratsennik](https://twitter.com/HalinaV)

## License

Project for [Holberton School](https://www.holbertonschool.com/)
