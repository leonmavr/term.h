#include <cstdio>
#include <sys/ioctl.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
//----------------------------------------------------------------------------------
// Linux POSIX terminal manipulation macros
//----------------------------------------------------------------------------------
#define TERM_ROWS 0
#define TERM_COLS 0
#define TERM_CLEAR() printf("\033[H\033[J")
#define TERM_GOTO_TOPLEFT() printf("\033[0;0H")
#define TERM_HIDE_CURSOR() printf("\e[?25l")
#define TERM_SHOW_CURSOR() printf("\e[?25h")
#define TERM_INIT() do {                                                \
    TERM_CLEAR();                                                       \
    TERM_HIDE_CURSOR();                                                 \
    TERM_GOTO_TOPLEFT();                                                \
    struct winsize w;                                                   \
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {                   \
        perror("ERROR: ioctl can't capture terminal's rows/columns.");  \
        return 1;                                                       \
    }                                                                   \
    g_termRows = w.ws_row;                                              \
    g_termCols = w.ws_col;                                              \
} while(0)
#define TERM_PRINT_AT(x, y, ch) printf("\033[%d;%dH%c", (y), (x), (ch));

/* terminal's rows */
int g_termRows = 0;
/* terminal's columns */
int g_termCols = 0;

} // extern "C"
#endif // __cplusplus
