*This project has been created as part of the 42 curriculum by zleullie.*

# get_next_line
Reading a line from a file descriptor is way too tedious.

## Description
The get_next_line project involves creating a C function that reads and returns a single line from a file descriptor. The main goal is to introduce the concept of static variables and state retention in C, while handling dynamic buffer allocations safely.

## Instructions
To integrate this project into your C programs, include the project header:
```c
#include "get_next_line.h"
```

Compile your source code files with the get_next_line source files, providing the required `BUFFER_SIZE` flag:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```
You can then call `get_next_line(fd)` on a file descriptor sequentially to extract strings line by line from the given file descriptor.

## Algorithm
This implementation uses a `static` buffer to keep track of leftover characters read past the immediate newline.
1. It first calls `read()` into a temporary buffer repeatedly, appending the contents to the `static` accumulation string until a newline string (`\n`) or End-Of-File (EOF) is encountered.
2. Once the condition is met, the accumulator string is split. The left portion (up to and including the `\n`) is extracted and returned to the caller.
3. The right portion (everything remaining after the `\n`) is duplicated and maintained within the `static` string, preserving it for the next call.

## Resources
- [Linux manual pages: read(2)](https://man7.org/linux/man-pages/man2/read.2.html)

_AI Disclaimer: GitHub Copilot was used to construct the initial `README.md`, which was then heavily modified, to simplify formatting and content inclusion requirements._