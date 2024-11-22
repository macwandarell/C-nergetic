#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else
#include <unistd.h>
#define SLEEP(seconds) sleep(seconds)
#endif

int main(void){
    print_border("*");
    f_string_format(1,"Welcome to the admin page");
    char s[100];
    date_d(s,sizeof(s));
    f_string_format(2, "%s        ",s);
    print_border("*");
}