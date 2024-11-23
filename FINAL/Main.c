#include <stdio.h>
#include "f_string.h"
#include <stdlib.h>
#ifdef _WIN32
    #define Register "registration.exe"
    #define Admin "admin.exe"
    #define Login "login.exe"
#else
    #define Register "./registration"
    #define Admin "./admin"
    #define Login "./login"
#endif

void printUI(){
    print_border("*");
    f_string_format(1, "Welcome to RoomLeloBhai.Com\n");
    char s[100];
    date_d(s,sizeof(s));
    f_string_format(2, "%s        \n",s);
    print_border("*");
}

int main(void){
    int flag = 1;
    while (flag){
        printUI();
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
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Exiting RoomLeloBhai.Com. Goodbye!\n");


}