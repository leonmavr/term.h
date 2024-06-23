# term.h
header to print characters at any coordinate on the terminal 

## Usage

Can be used both in C and C++. Requires a POSIX system.
```c
#inclue "term.h"

// ...
TERM_INIT();
TERM_PRINT_AT(100, 100, '#');
```
