#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "f_string.h"
#include <stdbool.h>

typedef struct Customer{
    char username[51];
    char email[255];
    char password[31];
    struct Customer *next;
}Customer;

void registerYourself();
Customer* next_node=NULL;

void freeMemory(Customer* head) {
    Customer* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
Customer* create_new_customer(char* username,char* email,char* password){
    Customer* new_customer=(Customer*)malloc(sizeof(Customer));
    strncpy(new_customer->username,username,50);
    new_customer->username[50]='\0';
    strncpy(new_customer->email,email,254);
    new_customer->email[254]='\0';
    strncpy(new_customer->password,password,30);
    new_customer->password[30]='\0';
    new_customer->next=NULL;
    return new_customer;}

void add_to_list(Customer** head,char* username,char* email,char* password){
    Customer* new_customer=create_new_customer(username,email,password);
    if(*head==NULL){
        *head=new_customer;
    }
    else{
        Customer* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_customer;}
}

bool usernameExists(struct Customer *current, char *username) {
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {  // Compare strings with strcmp
            return true;  // Username exists
        }
        current = current->next;
    }
    return false;
}

bool emailExists(struct Customer *current, char *email) {
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {  // Compare strings with strcmp
            return true;  // Username exists
        }
        current = current->next;
    }
    return false;
}

int main(){
    clear_console();
    int choice;

    FILE* fp=fopen("userCredentials.csv","r");

    if(!fp)
        printf("File does not exist\n.");
    else{
        int n=1024;
        char buffer[n];
        int row=0;
        int column=0;
        while(fgets(buffer,n,fp)){
            char username[51],email[255],password[31];
            column=0;
            row++;
            if(row==1)
                continue;
            char *value=strtok(buffer,", ");
            while(value){
                if(column==0){strncpy(username,value,50);
                    username[50]='\0';}
                if(column==1){strncpy(email,value,254);email[254]='\0';}
                if(column==2){strncpy(password,value,30);
                    password[30]='\0';}

                value= strtok(NULL,", ");
                column++;}
            add_to_list(&next_node,username,email,password);
            }
        }fclose(fp);
    
    do {
        // Display menu
        f_string_format(1, bold"================\n"end);
        f_string_format(1, orange"          RoomLeloBhai.com   \n"end);
        f_string_format(1, bold" ================\n\n"end);
        f_string_format(0, "\033[33m 1. Register Yourself\033[0m\n");
        f_string_format(0, "\033[33m 2. Exit\033[0m\n");
        f_string_format(1, bold" ==============================\n\n"end);
        printf("Enter your choice: ");
   
        scanf("%d", &choice);
        getchar();
        printf("\n"); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                registerYourself();
                break;
            case 2:
                printf(green"Exiting registration page. Goodbye!\n"end);
                SLEEP(4);
                freeMemory(next_node);
                clear_console();
        
                  // Free all allocated memory
                break;

            default:
                printf(red"Invalid input. Please try again.\n"end);
        }
    } while (choice != 2);return 0;}
        
void registerYourself(){

    char username[51], email[255], password[31];
    while (1) {
        printf("Enter a username: ");
        fgets(username,sizeof(username),stdin);
        username[strcspn(username,"\n")]='\0';
        if(strchr(username,' ')!=NULL){printf(red"Username cannot contain spaces.\n"end);continue;}
        else{
            
            if (usernameExists(next_node,username)) {
                printf(red"Username already exists. Please choose a different one.\n"end);
            } else {
                break;
            }}
    }

    while (1) {
        printf("Enter a email: ");
        fgets(email,sizeof(email),stdin);
        email[strcspn(email,"\n")]='\0';

        if (emailExists(next_node,email)) {
            printf(red"Email already exists. Please choose a different one.\n"end);
        } else {
            break;
        }
    }


    printf("Enter your password: ");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password,"\n")]='\0';
    printf("\n");
    // Success message

    FILE* fp1=fopen("userCredentials.csv","a");
    if(!fp1)
        printf("File does not exist\n.");
    else
    fprintf(fp1,"%s,%s,%s\n",username,email,password);
    fflush(fp1);

    printf(green"Customer registered successfully!\n"end);
    SLEEP(4);
    clear_console();
    add_to_list(&next_node, username, email, password);

   }
    
