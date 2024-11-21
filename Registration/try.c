#include <stdio.h>
#include <stdlib.h>
#include "f_string.h"
#include <string.h>

// Define the Customer structure
typedef struct Customer {
    char username[51];
    char email[255];
    char password[31];
    struct Customer* next; // Pointer to the next Customer in the list
} Customer;

// Function prototypes
void addCustomer(Customer** head);
void displayCustomers(Customer* head);
void deleteCustomer(Customer** head);
void freeMemory(Customer* head);

int main() {
    Customer* head = NULL; // Head pointer for the linked list
    int choice;

    do {
        // Display menu
        f_string_format(1, "\033[1m==============\033[0m");
        f_string_format(1, "\033[38;5;208m          TRIVAGO   \033[0m");
        f_string_format(1, "\033[1m  ==============\033[0m\n");
        f_string_format(0, "\033[33m 1. Register Yourself\033[0m");
        f_string_format(0, "\033[33m 2. Login\033[0m");
        f_string_format(0, "\033[33m 3. Exit\033[0m");
        f_string_format(1, "\033[1m ==============================\033[0m\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addCustomer(&head);
                break;
            case 2:
                displayCustomers(head);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                freeMemory(head);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to add a new customer
void addCustomer(Customer** head) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if (!newCustomer) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter username: ");
    fgets(newCustomer->username, 51, stdin);
    strtok(newCustomer->username, "\n"); // Remove newline character

    printf("Enter email: ");
    fgets(newCustomer->email, 255, stdin);
    strtok(newCustomer->email, "\n"); // Remove newline character

    printf("Enter password: ");
    fgets(newCustomer->password, 31, stdin);
    strtok(newCustomer->password, "\n"); // Remove newline character

    newCustomer->next = *head;
    *head = newCustomer;

    printf("Customer added successfully!\n");
}

// Function to display all customers
void displayCustomers(Customer* head) {
    if (head == NULL) {
        printf("No customers found.\n");
        return;
    }

    printf("\n===== Customer List =====\n");
    Customer* current = head;
    while (current) {
        printf("Username: %s\n", current->username);
        printf("Email: %s\n", current->email);
        printf("Password: %s\n", current->password);
        printf("-------------------------\n");
        current = current->next;
    }
}

// Function to delete a customer by username
void deleteCustomer(Customer** head) {
    if (*head == NULL) {
        printf("No customers found to delete.\n");
        return;
    }

    char username[51];
    printf("Enter username of the customer to delete: ");
    fgets(username, 51, stdin);
    strtok(username, "\n"); // Remove newline character

    Customer* current = *head;
    Customer* previous = NULL;

    while (current) {
        if (strcmp(current->username, username) == 0) {
            if (previous == NULL) {
                *head = current->next; // Deleting the head node
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Customer '%s' deleted successfully!\n", username);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Customer '%s' not found.\n", username);
}

// Function to free all allocated memory
void freeMemory(Customer* head) {
    Customer* current = head;
    while (current) {
        Customer* temp = current;
        current = current->next;
        free(temp);
    }
}
