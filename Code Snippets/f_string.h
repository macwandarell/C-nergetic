#ifndef F_STRING_H
#define F_STRING_H

// Function to format and print a string
// Parameters:
// - align: 1 for center-aligned, 0 for left-aligned
// - format: the format string (like printf)
// - ...: additional arguments for formatting
void f_string_format(int align, const char* format, ...);

#endif // F_STRING_H
