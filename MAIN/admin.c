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
    int flag = 1;
    char username[51], password[31];
    while (flag){
        printf("Enter username: ");
        fgets(username,sizeof(username),stdin);
        printf("Enter password: ");
        fgets(password,sizeof(password),stdin);
        if (strcmp(username,"admin")==0 && strcmp(password,"admin")==0){
            f_string_format(1,"Welcome admin");
            flag = 0;
        }
        else{
            f_string_format(1,"Invalid credentials");
        }
    }


}