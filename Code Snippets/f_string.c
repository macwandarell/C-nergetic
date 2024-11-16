#include "f_string.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/ioctl.h>
#endif

// Function to get the terminal width dynamically
static int get_terminal_width() {
    int width = 80; // Default width if detection fails

#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
#else
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        width = w.ws_col;
    }
#endif

    return width;
}

// Function to format and print a string with alignment
void f_string_format(int align, const char* format, ...) {
    int width = get_terminal_width(); // Get dynamic terminal width
    char buffer[1024];

    // Format the string
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    int len = strlen(buffer); // Length of the formatted string
    int padding = (width - len) / 2; // Calculate padding for centering

    if (align == 1) { // Center alignment
        if (padding > 0) {
            printf("%*s%s\n", padding, "", buffer);
        } else {
            printf("%s\n", buffer); // If the string is too wide
        }
    } else { // Left alignment
        printf("%s\n", buffer);
    }
}
