#include <stdio.h>
#include "f_string.h"
#include <stdlib.h>

#ifdef _WIN32
    #define Register "registration.exe"
    #define Admin "admin.exe"
    #define Login "login.exe"
    #define ViewPage "viewpage.exe"
    #define UserPage "userpage.exe"
    #define Selection "selection.exe"
    #define Billing "Billing.exe"

#else
    #define Register "./registration"
    #define Admin "./admin"
    #define Login "./login"
    #define ViewPage "./viewpage"
    #define UserPage "./userpage"
    #define Selection "./selection"
    #define Billing "./Billing"

#endif

void printMain(){
    print_border(whitebold"*"end);
    f_string_format(1, orange"Welcome to RoomLeloBhai.Com\n"end);
    char s[100];
    date_d(s,sizeof(s));
    f_string_format(2, "%s        \n",s);
    print_border(whitebold"*"end);
}

void printUser(){
    print_border(whitebold"*"end);
    f_string_format(1, orange"User Page\n"end);
    char s[100];
    date_d(s,sizeof(s));
    f_string_format(2, "%s        \n",s);
    print_border(whitebold"*"end);
}

int entry(){
    clear_console();
    int flag = 1;
    while (flag){
        printMain();
        printf("Login(L)\n");
        printf("Register(R)\n");
        printf("Admin(A)\n");
        printf("Exit(E)\n\n");
        printf("Enter your choice: ");
        char choice;
        scanf(" %c", &choice);
        getchar();
        printf("\n");

        if (choice == 'L' || choice == 'l') {
            flag = 0;
            system(Login);
        } else if (choice == 'R' || choice == 'r') {
            system(Register);
        } else if (choice == 'A' || choice == 'a') {
            system(Admin);
        } else if (choice == 'E' || choice == 'e') {
            printf("Thanks for visiting...\n");
            SLEEP(2);
            system("killall main");
            return 0;
        } else {
            printf(red"Invalid choice. Please try again.\n"end);
            SLEEP(2);
        }
        clear_console();
    }
    return 1;}

int hotel(){
    clear_console();
    int flag = 1;
    while(flag){
        printUser();
        printf("Book a Hotel(B)\n");
        printf("View Booked Hotels(V)\n");
        printf("Exit(E)\n");

        char choice;
        scanf(" %c", &choice);
        getchar();
        printf("\n");

        if (choice == 'V' || choice == 'v') {
            system(ViewPage);
        } else if (choice == 'B' || choice == 'b') {
            if (system(UserPage) == 1){
                flag = 0;
                entry();
            }else{
                system(Selection);
                system(Billing);
                flag = 0;
                entry();
            }
        } else if (choice == 'E' || choice == 'e') {
            entry();
        } else {
            printf(red"Invalid choice. Please try again.\n"end);
            SLEEP(2);
        }
        clear_console();
    }
    return 1;}

int main(void){
    clear_console();
    entry();
    hotel();
    return 0;
}
