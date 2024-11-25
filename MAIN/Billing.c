#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cr_green "\033[1;38;2;0;100;0m"
#define cr_yellow "\t \033[1;38;2;255;255;0m"
#define cr_w "\t \033[1;38;255;255;255m"
// #include <locale.h>
// #ifdef _WIN32
// #include <windows.h>
#define SLEEP(seconds) Sleep((seconds) * 1000)
// #else
#include <unistd.h>
#define SLEEP(seconds) sleep(seconds)
// #endif

#define MAX_LINE_LENGTH 1024

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


    FILE *fhotel = NULL;
    fhotel = fopen("details.csv","r");

    // Prices for the commmodities
    // Extra bed = Rs. 5000
    // Spa = 5000
    // Dinning = 2000
    // Pick-Up Services = 1000
    // Pets Room = 10000
    // None = 0

    char line[MAX_LINE_LENGTH];
    char hotel_name[50];
    char city[50];
    char location[150];
    


        


    f_string_format(1,"\b\b  Price for the Room :  ");
    printf("\n"); 
    f_string_format(1,"\b\b  No. Of Adults :  ");
    printf("\n"); 
    f_string_format(1,"\b\b  No. Of Kids : ");
    printf("\n"); 
    f_string_format(1,"\b\b  Price for the stay : 4343");
    printf("\n");
    f_string_format(1,"\b\b  Price for ext commodities : bed,pool");
    printf("\n");
    f_string_format(1,"\b\b  Discount for you :  10");
    printf("\n");
    int a=21;
    f_string_format(1,"\b\b  Payment to be made :  %d",a);
    printf("\n");

    print_border("-");
    
    f_string_format(1,"  Check In:\t12/23/23");
    printf("\n");
    f_string_format(1,"  Total Nights :\t12/13/23");
    printf("\n");
    f_string_format(1,"  Hotel Name :\tTaj");
    printf("\n");
    f_string_format(1,"  Location :\tMumbai");
    printf("\n");
    int b=265651;
    f_string_format(1,"  Extra Commodities :noo");
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

        if (confirm_payment_switch_for_loading=='Y' || confirm_payment_switch_for_loading=='y')
        {
            printf("\n");
            f_string_format(1,"  Thank you for choosing us!!!\n");
        }
        
        footer();
    }

    fclose(fhotel);
    return 0;
}

