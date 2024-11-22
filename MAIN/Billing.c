#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#define cr_green "\033[1;38;2;0;100;0m"
#define cr_yellow "\t \033[1;38;2;255;255;0m"
#define cr_w "\t \033[1;38;255;255;255m"
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif


int main()
{  
    setlocale(LC_ALL, "");

    #ifdef _WIN32
    // Set code page to UTF-8 for Windows console
    SetConsoleOutputCP(CP_UTF8);
    #endif


    clear_console();
    print_border("*");
    
    
    f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m\n");
    char arr[100];
    date_d(arr,sizeof(arr));
    f_string_format(2,"%s",arr);
    print_border("*");
    
    printf("\n");
    f_string_format(1,"\t\033[1;38;2;0;200;0mBilling Information\033[0m\n");

    print_border("-");
    print_border("-");
    f_string_format(0,"\t\t\t\t\t\t Price for the Room :\t\t8756");
    
   
    f_string_format(0,"\t\t\t\t\t\t Price for the stay :\t\t4343");
    f_string_format(0,"\t\t\t\t\t\t Price for ext commodities :\tbed,pool");
    f_string_format(0, "\t\t\t\t\t\t Discount for you :\t\t10");
    int a=21;
    f_string_format(0,"\t\t\t\t\t\t Payment to be made :\t\t%d",a);
    

   

    print_border("-"); 
    
    f_string_format(0,"\t\t\t\t\t\t   Check out :\t\t12/23/23");
    f_string_format(0,"\t\t\t\t\t\t   Check In :\t\t12/13/23");
    f_string_format(0,"\t\t\t\t\t\t   Hotel Name :\t\tTaj");
    f_string_format(0,"\t\t\t\t\t\t   Location :\t\tMumbai");
    int b=265651;
    f_string_format(0,"\t\t\t\t\t\t   Booking Date :\t%d",b);
    f_string_format(0,"\t\t\t\t\t\t   Commodities :\tnoo");
    print_border("-");

    printf("\n \n \n \n");
    f_string_format(1,"Customer Care :");
    f_string_format(1,"email id :");
    f_string_format(1,"CompanyName©");
    
    }

