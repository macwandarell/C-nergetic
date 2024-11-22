#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
// #define cr_green "\033[1;38;2;0;100;0m"
// #define cr_yellow "\t \033[1;38;2;255;255;0m"
// #define cr_w "\t \033[1;38;255;255;255m"

int main()
{  
    clear_console();
    print_border("\033[1m~\033[0m");
    
    f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m\n");    

    char arr[100];
    date_d(arr,sizeof(arr));
    f_string_format(2,"%s",arr);
    print_border("\033[1m~\033[0m");

    printf("\n");
    f_string_format(1,"\t\033[1;38;2;0;200;0m    Booking Information\033[0m\n");

    print_border("=");

    f_string_format(1," City : Mumbai \n");
    f_string_format(1," Hotel Name : Taj Palace\n");
    f_string_format(1," Location : Nariman Point \n");
    f_string_format(1," CheckIn Date : 21/4/2024 \n");
    f_string_format(1," CheckOut Date: 25/4/2024\n");
    f_string_format(1," Number Of Rooms : 2\n");
    f_string_format(1," Type Of Room : Deluxe\n");
    f_string_format(1," Total Payment : Rs.40000\n");
     f_string_format(1," Payment Status: Confirmed \n");

    print_border("=");

}
