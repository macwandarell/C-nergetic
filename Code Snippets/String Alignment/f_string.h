#ifndef F_STRING_H
#define F_STRING_H

// Function to format and print a string
// Parameters:
// - align: 0 for left-aligned, 1 for center-aligned, 2 for right-aligned
// - format: the format string (like printf)
// - ...: additional arguments for formatting
void f_string_format(int align, const char* format, ...);

#endif // F_STRING_H
