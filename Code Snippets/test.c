#include "f_string.h"

int main() {
    // Test case: Center-aligned string
    f_string_format(1, "Welcome to the %s module!", "f_string");

    // Test case: Left-aligned string
    f_string_format(0, "This is a left-aligned number: %d", 42);

    // Test case: Center-aligned long string
    f_string_format(1, "This is a demonstration of a dynamically adjusted terminal width.");

    return 0;
}
