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

void Company_name() 
{
    print_border("\033[1m~\033[0m");
    printf("\n");
    f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m");
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
    setlocale(LC_ALL, "");

    #ifdef _WIN32
    // Set code page to UTF-8 for Windows console
    SetConsoleOutputCP(CP_UTF8);
    #endif


    clear_console();
    
    Company_name();
    header("Billing Information");

    f_string_format(1,"\b\b  Price for the Room :  8756");
    printf("\n"); 
    f_string_format(1,"\b\b  Price for the stay :  4343");
    printf("\n");
    f_string_format(1,"\b\b  Price for ext commodities : bed,pool");
    printf("\n");
    f_string_format(1,"\b\b  Discount for you :  10");
    printf("\n");
    int a=21;
    f_string_format(1,"\b\b  Payment to be made :  %d",a);
    printf("\n");

    print_border("-");
    
    f_string_format(1,"  Check out :\t12/23/23");
    printf("\n");
    f_string_format(1,"  Check In :\t12/13/23");
    printf("\n");
    f_string_format(1,"  Hotel Name :\tTaj");
    printf("\n");
    f_string_format(1,"  Location :\tMumbai");
    printf("\n");
    int b=265651;
    f_string_format(1,"  Booking Date :\t%d",b);
    printf("\n");
    f_string_format(1,"  Commodities :noo");
    printf("\n");
    print_border("-");
    print_border("-");

    printf("\n ");
    f_string_format(1,"\b\bConfirm the Payment?(Y/N):");
    char confirm_payment;
    scanf("%c",&confirm_payment);
    printf("\n");


    //LOGIC FOR CONFIRMATION OF PAYMENT

    if(confirm_payment=='Y' || confirm_payment=='y')
    {    f_string_format(1,"We are loading you to the Payment Gateway...");
        printf("\n");
    }
    else if(confirm_payment=='N' || confirm_payment=='n')
    {   f_string_format(1,"Are you sure? Please enter Y or N:");

        getchar();
        scanf("%c",&confirm_payment);
        getchar();
        printf("\n");
        if(confirm_payment=='Y' || confirm_payment=='y')
        {    f_string_format(1,"We are loading you to the Payment Gateway...");
        printf("\n");
        }
        else if(confirm_payment=='N' || confirm_payment=='n')
        {   f_string_format(1,"You declined the Payment");
            printf("\n");
        }
        else
        {
            f_string_format(1,"Invalid Input");
        printf("\n");
        }
    }
    else
    {
        f_string_format(1,"Are you sure? Please enter Y or N:");
        getchar();
        scanf("%c",&confirm_payment);
        getchar();
        printf("\n");
        if(confirm_payment=='Y' || confirm_payment=='y')
        {    f_string_format(1,"We are loading you to the Payment Gateway...");
        printf("\n");
        }
        else if(confirm_payment=='N' || confirm_payment=='n')
        {   f_string_format(1,"You declined the Payment");
            printf("\n");
        }
        else
        {
            f_string_format(1,"Invalid Input");
        printf("\n");
        }
    }
    
    printf("\n \n");

    footer();
    
     SLEEP(2);


    //*****************************************************************************************************************/
    //  New Page for Payment Method
    //*****************************************************************************************************************/
    

    if(confirm_payment=='Y' || confirm_payment=='y')
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
        f_string_format(1," Enter the Payment Method :");

        int payment_method;
        scanf("%d",&payment_method);
        printf("\n");
        char confirm_last_time_payment;
        
        char details[100];
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
            
            f_string_format(1," Confirm the Payment?(Y/N):");
            getchar();
            scanf("%c",&confirm_last_time_payment);
            getchar();
            printf("\n");
            
            if(confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
               f_string_format(1,"Payment Successful");
            else if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
            {   
                
            }
            else
            {
                
            }
            break;
        case 2:
            f_string_format(1," Enter the Debit Card Number :");
            scanf("%s",details);
            
            f_string_format(1," Enter the CVV :");
            scanf("%s",details);
            
            f_string_format(1," Enter the Expiry Date :");
            scanf("%s",details);
            printf("\n");
            
            
            f_string_format(1," Confirm the Payment?(Y/N):");
            getchar();
            scanf("%c",&confirm_last_time_payment);
            getchar();
            printf("\n");
            
            if(confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
               f_string_format(1,"Payment Successful");
            else if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
            {   
            }
            else
            {
                
            }
            
                
            break;
        case 3: 
            f_string_format(1," Enter the Bank Name :");
            scanf("%s",details);
            
            f_string_format(1," Enter the Account Number :");
            scanf("%s",details);
            
            f_string_format(1," Enter the IFSC Code :");
            scanf("%s",details);
            printf("\n");
            
            f_string_format(1," Confirm the Payment?(Y/N):");
            getchar();
            scanf("%c",&confirm_last_time_payment);
            getchar();
            printf("\n");
            
            if(confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
               f_string_format(1,"Payment Successful");
            else if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
            {   
            }
            else
            {
               
            }
            break;
        case 4:
            f_string_format(1," Enter the UPI ID :");
            scanf("%s",details);
            
            f_string_format(1," Confirm the Payment?(Y/N):");
            getchar();
            scanf("%c",&confirm_last_time_payment);
            getchar();
            printf("\n");
            
            if(confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
               f_string_format(1,"Payment Successful");
            else if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
            {   
            }
            else
            {
                
            }
            break;
        
        case 5:
            f_string_format(1," Confirm the Payment?(Y/N):");
            getchar();
            scanf("%c",&confirm_last_time_payment);
            getchar();
            if(confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
            {
                printf("\n");
                f_string_format(1,"Payment will be done at the Hotel");
            }
            else if(confirm_last_time_payment=='N' || confirm_last_time_payment=='n')
            {   
            }
            else
            {
                
            }
            break;
        
        
        default:
            f_string_format(1,"Choose Proper Payment Method");
            break;
        }

        //Thanking you !!!

        if (confirm_last_time_payment=='Y' || confirm_last_time_payment=='y')
        {
            printf("\n");
            f_string_format(1,"  Thank you for choosing us!!!\n");
        }
        
        footer();
    }
    return 0;
}

