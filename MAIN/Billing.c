#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cr_green "\033[1;38;2;0;100;0m"
#define cr_yellow "\t \033[1;38;2;255;255;0m"
#define cr_w "\t \033[1;38;255;255;255m"
// #include <locale.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else
#include <unistd.h>
#define SLEEP(seconds) sleep(seconds)
#endif

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int confirm_payment_fun()
{   
    f_string_format(1,"\b\bConfirm the Payment?(Y/N):");
    char confirm_payment_in_fun;
    
    scanf(" %c",&confirm_payment_in_fun);
    while (getchar() != '\n');
    printf("\n");
    if(confirm_payment_in_fun=='Y' || confirm_payment_in_fun=='y')
    {   
        f_string_format(1,"Payment is confirmed");
        printf("\n");
        return 1;
    }
    else if(confirm_payment_in_fun=='N' || confirm_payment_in_fun=='n')
    {   f_string_format(1,"Are you sure? Please enter Y or N:");

        
        scanf(" %c",&confirm_payment_in_fun);
        while (getchar() != '\n');
        
        printf("\n");
        if(confirm_payment_in_fun=='Y' || confirm_payment_in_fun=='y')
        {    
            f_string_format(1,"Sure,Payment is declined!");
            printf("\n");
            return 0;
        }
        else if(confirm_payment_in_fun=='N' || confirm_payment_in_fun=='n')
        {   f_string_format(1,"OK,Confirming the Payment....");
            printf("\n");
            return 1;
        }
        else
        {
            f_string_format(1,"Invalid Input,Due to which Payment is declined");
            printf("\n");
            return 0;
        }
    }
    else
    {
        f_string_format(1,"Invalid Input");
        printf("\n");
        f_string_format(1,"You want to continue and Confirm the Payment? Please enter Y or N:");
        
        scanf(" %c",&confirm_payment_in_fun);
        while (getchar() != '\n');
        
        printf("\n");
        if(confirm_payment_in_fun=='Y' || confirm_payment_in_fun=='y')
        {    
            f_string_format(1,"Ok,Confirming the Payment....");
            printf("\n");
            return 1;
        }
        else if(confirm_payment_in_fun=='N' || confirm_payment_in_fun=='n')
        {   
            f_string_format(1,"Sure,Payment is declined!");
            printf("\n");
            return 0;
        }
        else
        {
            f_string_format(1,"Invalid Input,Due to which Payment is declined");
            printf("\n");
            return 0;
        }
    }


}

void Company_name() 
{
    print_border("\033[1m~\033[0m");
    printf("\n");
    f_string_format(0,"\033[1;38;2;255;165;0mRoom.Lelo.Bhai.com\033[0m");
    printf("\n");
    char arr[100];
    date_d(arr,sizeof(arr));
    f_string_format(2,"%s",arr);
    print_border("\033[1m~\033[0m");
    printf("\n");
}
void header(char ar[100])
{
    f_string_format(1,"\t\033[1;38;2;0;200;0m\t%s\033[0m\n",ar);
    print_border("-");
    print_border("-");
}
void footer()
{
    printf("\n");
    print_border("-");
    f_string_format(1,"Customer Care :98989XXXXX");
    printf("\n");
    f_string_format(1,"email id :temp@gmail.com");
    printf("\n");
    f_string_format(1,"CompanyName | (C) ");
}

void remove_newline(char *str)
            {
            size_t len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') 
            {
            str[len - 1] = '\0';
            }

            }


// Main Function


int main()
{  
    // setlocale(LC_ALL, "");

    // #ifdef _WIN32
    // // Set code page to UTF-8 for Windows console
    // SetConsoleOutputCP(CP_UTF8);
    // #endif

    clear_console();
    
    Company_name();
    header("Billing Information");



    FILE *fchoice;
    fchoice = fopen("customer_choice.csv","r");


    char line[1000];
    

    // I HAVE TO IMPORT DATA FROM ANOTHER FOLDER NAMED "User Main Page" FILE NAME IS EXPERIMENTAL.C
    // AND I WANT THE PRICE AND ALL FROM THE FILE NAMED "details.csv" 
    //SO WRITE ME A CODE FOR THAT
    // I HAVE TO PRINT THE DETAILS OF THE HOTEL AND THE CUSTOMER DETAILS
    // I HAVE TO PRINT THE TOTAL AMOUNT TO BE PAID
    // I HAVE TO PRINT THE PAYMENT METHOD
    
    //code for reading data form the details.csv file
    

    char line1[1000];
    int nights;
    int rooms;
    char type[50];
    int price_per_room;
    int adults;
    int kids;
    char commodities[8];


    // we defined this for our purpose
    int commodities_price[7]={2000,3000,3000,5000,5000,2000,10000};
    char commodities_details[7][50]={"Breakfast","Lunch","Dinner","Extra Bed","Spa","Pick-up Service","Pet-rooms"};



    

    //code for reading data form the customer_choice.csv
    int index;
    char hotel_name[50];
    char city[50];
    int price_single;
    int price_deluxe;
    int price_villa;
    int price_luxury;
    char address[30];
    FILE *fdetails=fopen("details.csv","r");
    

    char check_indate[50];
    if (fgets(line1, 1000, fdetails) != NULL)
    {
        
        nights = atoi(strtok(line1, ","));
        rooms = atoi(strtok(NULL, ","));
        strcpy(type, strtok(NULL, ","));
        price_per_room = atoi(strtok(NULL, ","));
        strcpy(check_indate, strtok(NULL, ","));
        adults = atoi(strtok(NULL, ","));
        kids = atoi(strtok(NULL, ","));
        strcpy(commodities, strtok(NULL, ","));
    }
  

    
    


    if (fgets (line, 1000, fchoice) != NULL)
    {
        index = atoi(strtok(line, ","));
        strcpy(hotel_name, strtok(NULL, ","));
        strcpy(city, strtok(NULL, ","));
        price_single = atoi(strtok(NULL, ","));
        price_deluxe = atoi(strtok(NULL, ","));
        price_villa = atoi(strtok(NULL, ","));
        price_luxury = atoi(strtok(NULL, ","));
        strcpy(address, strtok(NULL, ","));
    }
    //random number for discount
    srand(time(0));
    int price_room=price_per_room*rooms;
    int discount = (rand() % 5) + 1;
    int price_stay=price_room*nights;
    int int_price_commodities=0;
    int mrp=price_stay+int_price_commodities;
    int total_price=mrp-((mrp*discount)/100);
    char extra_commodities[7][50];
    
    char buffer1[1000] = {0};


    for (int  i = 0; i < strlen(commodities); i++)
    {
        if (commodities[i]=='1')
        {
            int_price_commodities+=commodities_price[i];
            strcat(buffer1, commodities_details[i]);
            strcat(buffer1, ", ");
        }
    }
    

    

    
    
    f_string_format(1,"\b\b  Price for each Room :  Rs.%d",price_per_room);//details.csv
    printf("\n");
    f_string_format(1,"\b\b  No. Of Rooms :  %d",rooms);//details.csv
    printf("\n");
    f_string_format(1,"\b\b  Price for the rooms:  Rs.%d",price_room);//details.csv
    printf("\n");
    f_string_format(1,"\b\b  No. Of Adults :  %d",adults);//details.csv
    printf("\n"); 
    f_string_format(1,"\b\b  No. Of Kids : %d",kids);//details.csv
    printf("\n"); 
    f_string_format(1,"\b\b  Price for the stay : Rs.%d",price_stay);//multiply the no. of nights with the price of the rooms
    printf("\n");
    f_string_format(1,"\b\b  Price for ext commodities : Rs.%d",int_price_commodities);//details.csv
    printf("\n");
    f_string_format(1,"\b\b  Total MRP :  Rs.%d",mrp);//price of stay + price of commodities
    printf("\n");
    f_string_format(1,"\b\b  Discount for you :  %d %%",discount);//random genetated
    printf("\n");
    
    f_string_format(1,"\b\b  Payment to be made :  Rs.%d",total_price);//price of stay + price of commodities - discount
    printf("\n");

    print_border("-");
    
    f_string_format(1,"  Check In: %s",check_indate);
    printf("\n");
    f_string_format(1,"  Total Nights : %d",nights);//details.csv
    printf("\n");
    f_string_format(1,"  Hotel Name : %s",hotel_name);//customer_choice.csv
    printf("\n");
    f_string_format(1,"  Location : %s",city);//customer_choice.csv
    printf("\n");
    int b=265651;
    f_string_format(1,"Extra Commodities : %s",buffer1);//details.csv
    printf("\n");
    print_border("-");
    print_border("-");

    printf("\n ");

    



    
    int confirm_payment=confirm_payment_fun();          //if 1 -->page 1 confirmed so ,load next page
    int confirm_payment_switch_for_loading;             //if 1 -->page 2 confirmed so ,load this in view hotel
    if (confirm_payment==0)                             //for printing in this page
    {
        f_string_format(1,"");
        printf("\n");
    }
    else
    {
        
        f_string_format(1,"  We are loading you to the Payment Gateway...");
        printf("\n");
    }
    
    printf("\n \n");

    footer();
    
    SLEEP(2);


    //*****************************************************************************************************************/
    //  New Page for Payment Method
    //*****************************************************************************************************************/
    

    if(confirm_payment==1)                          //Page 2 Pop ups
    {
        clear_console();
        Company_name();
        header("RazorPay");
        f_string_format(1," Choose the Payment Method :");
        printf("\n");
        f_string_format(1," 1. Credit Card");
        printf("\n");
        f_string_format(1," 2. Debit Card");
        printf("\n");
        f_string_format(1," 3. Net Banking");
        printf("\n");
        f_string_format(1," 4. UPI");
        printf("\n");
        f_string_format(1," 5. Cash");
        printf("\n");
        
        printf("\n");
        

        
        char confirm_last_time_payment;
        
        char details[100];
        int flag=1;
        while (flag)
        {
            f_string_format(1," Enter the Payment Method :");
            int payment_method;
            scanf("%d",&payment_method);
            printf("\n");
            switch (payment_method)   
            {
            case 1:
                f_string_format(1," Enter the Credit Card Number :");
                scanf("%s",details);
                
                f_string_format(1," Enter the CVV :");
                scanf("%s",details);
                
                f_string_format(1," Enter the Expiry Date :");
                scanf("%s",details);
                printf("\n");
                
                confirm_payment_switch_for_loading=confirm_payment_fun();
                if (confirm_payment_switch_for_loading==0)
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                else
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                
                flag=0;
                break;
            case 2:
                f_string_format(1," Enter the Debit Card Number :");
                scanf("%s",details);
                
                f_string_format(1," Enter the CVV :");
                scanf("%s",details);
                
                f_string_format(1," Enter the Expiry Date :");
                scanf("%s",details);
                printf("\n");
                
                
                
                confirm_payment_switch_for_loading=confirm_payment_fun();
                if (confirm_payment_switch_for_loading==0)
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                else
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                
                
                flag=0;  
                break;
            case 3: 
                f_string_format(1," Enter the Bank Name :");
                scanf("%s",details);
                
                f_string_format(1," Enter the Account Number :");
                scanf("%s",details);
                
                f_string_format(1," Enter the IFSC Code :");
                scanf("%s",details);
                printf("\n");
                
            
                confirm_payment_switch_for_loading=confirm_payment_fun();
                if (confirm_payment_switch_for_loading==0)
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                else
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                flag=0;
                break;
            case 4:
                f_string_format(1," Enter the UPI ID :");
                scanf("%s",details);
                
                
                confirm_payment_switch_for_loading=confirm_payment_fun();
                if (confirm_payment_switch_for_loading==0)
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                else
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                flag=0;
                break;
            
            case 5:
                
                confirm_payment_switch_for_loading=confirm_payment_fun();
                if (confirm_payment_switch_for_loading==0)
                {
                    f_string_format(1,"");
                    printf("\n");
                }
                else
                {
                    f_string_format(1,"Payment will be done at the hotel!");
                    printf("\n");
                }
                flag=0;
                break;
            
            
            default:
                f_string_format(1,"Choose Proper Payment Method\n\n");
                
                flag=1;
                break;
            }
        }
        //Thanking you !!!



        if (confirm_payment_switch_for_loading)
        {
            printf("\n");
            f_string_format(1,"  Thank you for choosing us!!!\n");
            
            
            remove_newline(address);

            FILE *fuser_info;
            fuser_info = fopen("tempUser.csv","r");
            char line2[1000];
            char user_name[50];
            char password[50];

            if (fgets(line2, 1000, fuser_info) != NULL)
            {
                strcpy(user_name, strtok(line2, ","));
                strcpy(password, strtok(NULL, ","));
            }

            FILE *fuser_booked_data;
            fuser_booked_data = fopen("user_booked_data.csv","a");
            
            //city,hotelname,location,checkindate,nights,rooms,type_of_room,total_price
            fprintf(fuser_booked_data,"%s,%s,%s,%s,%s,%s,%d,%d,%s,%d\n",user_name,password,city,hotel_name,address,check_indate,nights,rooms,type,total_price);

            
            fclose(fuser_booked_data);
            fclose(fuser_info);







        }
        
        footer();
    }










    fclose(fchoice);
    fclose(fdetails);
    return 0;
}

