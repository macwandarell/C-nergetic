#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Customer{
    char username[51];
    char email[255];
    char password[31];
    struct Customer *next;
}Customer;
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
int main(){
    Customer* next_node=NULL;
    FILE* fp=fopen("/mnt/Users/Yashvi Mehta/OneDrive/Desktop/C-nergetic/Registration/output.csv","r");

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
            Customer* new_customer=(Customer*)malloc(sizeof(Customer));
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
    Customer* temp = next_node;
        while (temp != NULL) {
            printf("Username: %s, Email: %s, Password: %s\n", temp->username, temp->email, temp->password);
            temp = temp->next;
        }
    
    /*printf("%i",i);
    FILE* fp1=fopen("/mnt/Users/Yashvi Mehta/OneDrive/Desktop/C-nergetic/Registration/output.csv","a+");*/
    
    
    /*char string1[10];
    scanf("%s",string1);
    getchar();
    printf("%s\n",string1);*/
    return 0;
}
