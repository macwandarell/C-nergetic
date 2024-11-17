#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_csv(const char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "1,John Doe,25,88.5\n");
    fprintf(file, "2,Jane Smith,30,92.3\n");
    fprintf(file, "3,Sam Brown,22,74.0\n");

    fclose(file);
}

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, ",");
        while (token) {
            printf("%s", token);
            token = strtok(NULL, ",");
        }
    }
    fclose(file);
}

void registration() {
    print_border("*");
    f_string_format(1, "Welcome To The Registration Page!");
    char s[100];
    date_d(s,sizeof(s));
    f_string_format(2, "%s",s);

}

int main() {
    const char *filename = "data.csv";
//    write_csv(filename);
//    read_csv(filename);
    registration();
    return 0;
}
