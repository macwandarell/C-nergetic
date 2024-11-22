#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#define cr_green "\033[1;38;2;0;100;0m"
#define cr_yellow "\t \033[1;38;2;255;255;0m"
#define cr_w "\t \033[1;38;255;255;255m"
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP(seconds) Sleep((seconds) * 1000)
#else
#include <unistd.h>
#define SLEEP(seconds) sleep(seconds)
#endif


int main()
{  
    setlocale(LC_ALL, "");

    #ifdef _WIN32
    // Set code page to UTF-8 for Windows console
    SetConsoleOutputCP(CP_UTF8);
    #endif


    clear_console();
    print_border("\033[1m~\033[0m");
    
    printf("\n");
    f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m");
    printf("\n");
    char arr[100];
    date_d(arr,sizeof(arr));
    f_string_format(2,"%s",arr);
    print_border("\033[1m~\033[0m");
    
    printf("\n");
    f_string_format(1,"\t\033[1;38;2;0;200;0mBilling Information\033[0m\n");

    print_border("-");
    print_border("-");
    f_string_format(0,"\t\t\t\t\t\t Price for the Room :\t\t8756");
    printf("\n"); 
    f_string_format(0,"\t\t\t\t\t\t Price for the stay :\t\t4343");
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t Price for ext commodities :\tbed,pool");
    printf("\n");
    f_string_format(0, "\t\t\t\t\t\t Discount for you :\t\t10");
    printf("\n");
    int a=21;
    f_string_format(0,"\t\t\t\t\t\t Payment to be made :\t\t%d",a);
    printf("\n");
    

   

    print_border("-"); 
    
    f_string_format(0,"\t\t\t\t\t\t   Check out :\t\t12/23/23");
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t   Check In :\t\t12/13/23");
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t   Hotel Name :\t\tTaj");
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t   Location :\t\tMumbai");
    printf("\n");
    int b=265651;
    f_string_format(0,"\t\t\t\t\t\t   Booking Date :\t%d",b);
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t   Commodities :\tnoo");
    printf("\n");
    print_border("-");
    print_border("-");
    printf("\n ");
    printf("\t\t\t\t\t\t  Confirm the Payment?(Y/N):");
    char confirm_payment;
    scanf("%c",&confirm_payment);
    printf("\n");
    if(confirm_payment=='Y' || confirm_payment=='y')
    {    f_string_format(0,"\t\t\t\t\t\t\t Payment Successful");
        printf("\n");
    }
    else if(confirm_payment=='N' || confirm_payment=='n')
    {   f_string_format(0,"\t\t\t\t\t\t\t Payment Failed");
        printf("\n");
    }
    else
    {
        f_string_format(0,"\t\t\t\t\t\t\t Invalid Input");
        printf("\n");
    }
    
    printf("\n \n");
    f_string_format(0,"\t\t\t\t\t\t\t Customer Care :");
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t\t email id :");
    printf("\n");
    f_string_format(0,"\t\t\t\t\t\t\t CompanyName | (C) ");
    
     SLEEP(2);



     //  New Page for Payment Method

    

    if(confirm_payment=='Y' || confirm_payment=='y')
    {
        clear_console();
        print_border("~");
        f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m\n");
        char arr[100];
        date_d(arr,sizeof(arr));
        f_string_format(2,"%s",arr);
        print_border("~");
        printf("\n");
        f_string_format(1,"\t\033[1;38;2;0;200;0mRazroPay\033[0m\n");
        print_border("-");
        print_border("-");
        printf("\t\t\t\t\t\t Choose the Payment Method :");
        printf("\n");
        printf("\t\t\t\t\t\t 1. Credit Card");
        printf("\n");
        printf("\t\t\t\t\t\t 2. Debit Card");
        printf("\n");
        printf("\t\t\t\t\t\t 3. Net Banking");
        printf("\n");
        printf("\t\t\t\t\t\t 4. UPI");
        printf("\n");
        printf("\t\t\t\t\t\t 5. Cash");
        printf("\n");
        printf("\t\t\t\t\t\t 6. Other");
        printf("\n");
        printf("\t\t\t\t\t\t Enter the Payment Method :");

        int payment_method;
        scanf("%d",&payment_method);
        printf("\n");
        char confirm_last_time_payment;
        char details[100];
        switch (payment_method)   
        {
        case 1:
            printf("\t\t\t\t\t\t Enter the Credit Card Number :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Enter the CVV :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Enter the Expiry Date :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Confirm the Payment?(Y/N):");
            scanf("%c",&confirm_last_time_payment);
            printf("\n");
            if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
               printf("\t\t\t\t\t\t\t Payment Failed");

            else
                printf("\t\t\t\t\t\t\t Invalid Input");
            break;
        case 2:
            printf("\t\t\t\t\t\t Enter the Debit Card Number :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Enter the CVV :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Enter the Expiry Date :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Confirm the Payment?(Y/N):");
            scanf("%c",&confirm_last_time_payment);
            printf("\n");
            if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
                printf("\t\t\t\t\t\t\t Payment Failed");
                
            else
                printf("\t\t\t\t\t\t\t Invalid Input");
                
            break;
        case 3: 
            printf("\t\t\t\t\t\t Enter the Bank Name :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Enter the Account Number :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Enter the IFSC Code :");
            scanf("%s",details);
            printf("\n");
            printf("\t\t\t\t\t\t Confirm the Payment?(Y/N):");
            scanf("%c",&confirm_last_time_payment);
            if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
                printf("\t\t\t\t\t\t\t Payment Failed");
            else
                printf("\t\t\t\t\t\t\t Invalid Input");
            break;
        case 4:
            printf("\t\t\t\t\t\t Enter the UPI ID :");
            printf("\t\t\t\t\t\t Confirm the Payment?(Y/N):");
            scanf("%c",&confirm_last_time_payment);
            if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
                printf("\t\t\t\t\t\t\t Payment Failed");
            else
                printf("\t\t\t\t\t\t\t Invalid Input");
            break;
        
        case 5:
            printf("\t\t\t\t\t\t Confirm the Payment?(Y/N):");
            scanf("%c",&confirm_last_time_payment);
            if(confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
                printf("\t\t\t\t\t\t\t Payment will be done at the Hotel");
            else if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
                printf("\t\t\t\t\t\t\t Payment Failed");
            else
                printf("\t\t\t\t\t\t\t Invalid Input");
            break;
        case 6:
            printf("\t\t\t\t\t\t Enter the Payment Method :");
            printf("\t\t\t\t\t\t Enter the Details :");
            printf("\t\t\t\t\t\t This method will be done manually at the Hotel");
            printf("\t\t\t\t\t\t Confirm the Payment?(Y/N):");
            scanf("%c",&confirm_last_time_payment);
            if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
                printf("\t\t\t\t\t\t\t Payment Failed");
            else
                printf("\t\t\t\t\t\t\t Invalid Input");
            break;
        
        default:
            printf("\t\t\t\t\t\t\t Invalid Input");
            break;
        }

        if (confirm_last_time_payment=='Y')
        {
            f_string_format(0,"\t\t\t\t\t\t\t Payment Successful");
            f_string_format(0,"\t\t\t\t\t\t\t Thank you for choosing us");
        }
        

        print_border("\n");
        print_border("-");
        print_border("-");
        printf("\n \n \n");
        f_string_format(0,"\t\t\t\t\t\t\t Customer Care :");
        printf("\n");
        f_string_format(0,"\t\t\t\t\t\t\t email id :");
        printf("\n");
        f_string_format(0,"\t\t\t\t\t\t\t CompanyName | (C) ");
        printf("\n");




    }

    // printf("\n \n \n");
    // f_string_format(0,"\t\t\t\t\t\t\t Customer Care :");
    // f_string_format(0,"\t\t\t\t\t\t\t email id :");
    // f_string_format(0,"\t\t\t\t\t\t\t CompanyName | (C) ");
    
    return 0;
}

