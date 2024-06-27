# term.h
Simple header-only utility to make it easier to print characters at any coordinate on the terminal.
It is compatible both with C and C++;

## Usage

### ASCII characters

```c
#include "term.h"

int main() {
    TERM_INIT();
    for (int i = 0; i < 10; i++) TERM_PRINT_AT(2 + (int)i/2, 4 + i, '#');
    return 0;
}
```
Will print:
```

   ##
     ##
       ##
         ##
           ##
```

### Unicode characters

It is additionally able to print Unicode 'pixels', i.e. two Unicode full blocks next to each other.
Therefore each 'pixel' takes 2x1 cells on the terminal. The reason for this is so that they look square-ish.

So printing a 'pixel' at (x,y) takes up cells (2x, y), (2x+1, y).

```c
#include "term.h"

int main() {
    TPRINT_WINIT();
    TPRINT_PIXEL(2, 2);
    TPRINT_PIXEL(3, 3);
    TPRINT_PIXEL(4, 4);
    TPRINT_PIXEL(3, 4);
    TPRINT_WPRINT_AT(10, 4, L'\u24fe');
    return 0;
}
```
Will print:
```

   ██
     ██
     ████⓾
```
