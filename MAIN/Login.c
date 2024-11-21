#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer{
    char username[51];
    char email[255];
    char password[31];
    struct Customer *next;
}Customer;

void printCustomers(Customer* head) {
    Customer* current = head;
    while (current != NULL) {
        printf("Username: %s, Email: %s, Password: %s\n", current->username, current->email, current->password);
        current = current->next;
    }
}


Customer* createCustomer(const char* username, const char* email, const char* password) {
    Customer* newCustomer = (Customer*) malloc (sizeof(Customer));

    strcpy(newCustomer->username, username);
    strcpy(newCustomer->email, email);
    strcpy(newCustomer->password, password);

    newCustomer->next = NULL;
    return newCustomer;
}

void appendCustomer(Customer** head, const char* username, const char* email, const char* password) {
    Customer* newCustomer = createCustomer(username, email, password);

    if (*head == NULL) {
        *head = newCustomer;
    } else {
        Customer* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCustomer;
    }
}



void login() {
    FILE* fp = fopen("output.csv", "r");
    if (!fp) {
    printf("Error: Unable to open the file.\n");
    return;
    }
    char buffer[1024];
    int row = 1;
    Customer* customerList = NULL;
    while (fgets(buffer, sizeof(buffer), fp)) {
        int column = 0;

        char* username = strtok(buffer, ",");
        char* email = strtok(NULL, ",");
        char* password = strtok(NULL, ",");
        password[strcspn(password, "\n")] = '\0'; // Remove trailing newline
        appendCustomer(&customerList, username, email, password); // Add to the linked list
        row++;
    }
    fclose(fp);

    print_border("*");
    f_string_format(1, "Welcome To The Registration Page!");
    char s[100];
    date_d(s,sizeof(s));
    f_string_format(2, "%s        ",s);
    print_border("*"); 

    printCustomers(customerList);
    printf("HEllo");
}

int main() {
    const char *filename = "data.csv";
    login();
    return 0;
}
