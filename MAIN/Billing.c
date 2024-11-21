#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
int main()
{
    clear_console();
    print_border("-");
    
    f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m\n");
    char arr[100];
    date_d(arr,sizeof(arr));
    f_string_format(2,"%s",arr);
    print_border("-");
    printf("\n");
    f_string_format(1,"\033[1;38;2;255;255;255mBilling Information\033[0m\n");

    f_string_format(0,"\033[1;38;2;255;25500;255m    **********************************************\033[0m");
    f_string_format(2,"\033[1;38;2;255;255;255mCheckvout\033[0m");

    f_string_format(0,"\t \033[1;38;2;255;255;255m<  Price for the Room:                >\033[0m");
    f_string_format(2,"\033[1;38;2;255;255;255mCheck In\033[0m");

    f_string_format(0,"\t \033[1;38;2;255;255;255m<  Price for the stay:                >\033[0m");
    f_string_format(2,"\033[1;38;2;255;255;255mHotel name\033[0m");

    f_string_format(0,"\t \033[1;38;2;255;255;255m<  Price for ext commodities:         >\033[0m");
    f_string_format(2,"\033[1;38;2;255;255;255mLocation\033[0m");

    f_string_format(0,"\t \033[1;38;2;0;100;0m<  Discount for you:                  >\033[0m");
    f_string_format(2,"\033[1;38;2;255;255;255mBooking date\033[0m");
    int a=21;
    f_string_format(0,"\t \033[1;38;2;255;255;0m<  Payment to be made: %d             >\033[0m",a);
    
    f_string_format(2,"\033[1;38;2;255;255;255mCommodities given\033[0m");
    f_string_format(0,"\033[1;38;2;255;25500;255m    **********************************************\033[0m");
    printf("\n \n \n \n");
    f_string_format(1, "Customer Care:");
    f_string_format(1, "email id:");
    f_string_format(1,"\u00A9\n");


}