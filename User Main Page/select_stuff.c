#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "f_string.h"
#ifdef _WIN32
#include <windows.h>
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else
#include <unistd.h>
#define SLEEP(seconds) sleep(seconds)
#endif
int main(){
    FILE *f1=fopen("details.csv","w");
    printf("How many nights? ");
    int nights;
    scanf("%i",&nights);
    getchar();
    char date[8];
    printf("From which date? (Please enter in dd/mm/yy format)");
    fgets(date,sizeof(date),stdin);
    date[strcspn(date,"\n")]='\0';
    printf("Select the room type:\n1 : Single Room\n2 : Deluxe Room\n3 : Super Deluxe\n4 : Luxury\n");
    int type_num;
    char type[15];
    int i=0;
    while(!i){
        printf("Type number: ");
        scanf("%i",&type_num);
        getchar();
        if(type_num==1){strncpy(type,"Single",sizeof(type));i=1;}
        else if(type_num==2){strncpy(type,"Deluxe",sizeof(type));i=1;}
        else if(type_num==3){strncpy(type,"Super",sizeof(type));i=1;}
        else if(type_num==4){strncpy(type,"Luxury",sizeof(type));i=1;}
        else{printf("Type correct number.\n");}}
    int adults,kids,rooms;
    int a=0;
    while(!a){
        printf("Enter the number of adults: ");
        scanf("%d",&adults);
        getchar();
        printf("Enter the number of kids: ");
        scanf("%d",&kids);
        getchar();
        printf("Enter the number of rooms needed: ");
        scanf("%d",&rooms);
        getchar();
        int r1 =0;
        if(adults%2==0){
            r1+=adults/2;
            if(kids>r1){
                if((kids-r1)%3==0) r1+=(kids-r1)/3;
                else r1+=(kids-r1)/3 + 1;
            }
        }
        else{
            r1+=adults/2 + 1;
            if(kids>r1){
                if((kids-r1-1)%3==0){
                    r1+=(kids-r1-1)/3;}
                else r1+=(kids-r1-1)/3 + 1;
            }
        }
        printf("Minimum number of rooms needed are %d\n",r1);
        if(rooms<r1){
            printf("Sorry you need to book %d more rooms to accomodate everyone.",r1-rooms);
        }
        else {printf("Congratulations, your rooms have been booked successfully!!!!");a=1;}}
    clear_console();
    char commodities[7];
    printf("Select extra commodities:(type 0 if you don't want or 1 if you want)\n");
    printf("Breakfast: ");
    scanf("%c",&commodities[0]);
    getchar();
    printf("Lunch: ");
    scanf("%c",&commodities[1]);
    getchar();
    printf("Dinner: ");
    scanf("%c",&commodities[2]);
    getchar();
    printf("Extra Bed: ");
    scanf("%c",&commodities[3]);
    getchar();
    printf("Spa: ");
    scanf("%c",&commodities[4]);
    getchar();
    printf("Pick-up Service: ");
    scanf("%c",&commodities[5]);
    getchar();
    printf("Pet-rooms: ");
    scanf("%c",&commodities[6]);
    getchar();
    fprintf(f1,"%i,%i,%s,%s,%i,%i,%s",nights,rooms,type,date,adults,kids,commodities);
    fclose(f1);
    return 0;

}
   // FILE 1(for hotel):
   // name,city,price_of_single,price_of_deluxe,price_of_super_deluxe,price_of_luxury,address.

   // FILE 2(for price):
   // nights(int),no_of_rooms,room_type(string),date(string),no_of_adults,no_of_kids,extra(string: 01010101)
