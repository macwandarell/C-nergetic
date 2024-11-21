#include <stdio.h>

int main() {
    // Use 256-color mode for orange (code 208)
    printf("\033[38;5;208mThis text is orange (256-color mode).\033[0m\n");

    return 0;
}
