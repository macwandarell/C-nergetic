#include <stdio.h>
#include <string.h>

typedef struct Customer{
    char username[51];
    char email[255];
    char password[31];
}Customer;
int main(){
    int p=100;
    struct Customer customers[p];
    int i=0;
    FILE* fp=fopen("/mnt/Users/Yashvi Mehta/OneDrive/Desktop/C-nergetic/Registration/output.csv","r");

    if(!fp)
        printf("File does not exist\n.");
    else{
        int n=1024;
        char buffer[n];
        int row=0;
        int column=0;
        while(fgets(buffer,n,fp)){
            column=0;
            row++;
            if(row==1)
                continue;
            char *value=strtok(buffer,", ");
            
            while(value){
                if(column==0){strcpy(customers[i].username,value);}
                if(column==1){strcpy(customers[i].email,value);}
                if(column==2){strcpy(customers[i].password,value);i++;}      
               
                value= strtok(NULL,", ");
                column++;}
        }fclose(fp);
    }
    printf("%i",i);

    /*char string1[10];
    scanf("%s",string1);
    getchar();
    printf("%s\n",string1);*/
    return 0;
}
