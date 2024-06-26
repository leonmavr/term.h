# term.h
header to print characters at any coordinate on the terminal 

## Usage

Can be used both in C and C++. Requires a POSIX system. For example
```c
#include "term.h"

int main() {
    TERM_INIT();
    for (int i = 0; i < 10; i++) TERM_PRINT_AT(2 + (int)i/2, 4 + i, '#')
    return 0;
}
```
Prints:
```

   ##
     ##
       ##
         ##
           ##
```
