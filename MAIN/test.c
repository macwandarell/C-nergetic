#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
#define cr_green "\033[1;38;2;0;100;0m"
#define cr_yellow "\t \033[1;38;2;255;255;0m"
#define cr_w "\t \033[1;38;255;255;255m"

int main()
{
    clear_console();
    print_border("-");
    
    f_string_format(0, "                              \033[1;38;2;255;165;0mTrivago\033[0m\n");
    char arr[100];
    date_d(arr, sizeof(arr));
    f_string_format(2, "                              %s", arr);
    print_border("-");
    printf("\n");
    f_string_format(1, "                              \033[1;38;2;255;255;255mBilling Information\033[0m\n");

    f_string_format(1, "                              \033[1;38;2;255;25500;255m**********************************************\033[0m");
    f_string_format(1, "                              " cr_w "<  Price for the Room:                >\033[0m");
    f_string_format(1, "                              " cr_w "<  Price for the stay:                >\033[0m");
    f_string_format(1, "                              " cr_w "<  Price for ext commodities:         >\033[0m");
    f_string_format(1, "                              " cr_green " <  Discount for you:                  >\033[0m");
    int a = 21;
    f_string_format(1, "                              " cr_yellow "<  Payment to be made: %d             >\033[0m", a);
    f_string_format(1, "                              \033[1;38;2;255;25500;255m**********************************************\033[0m");

    printf("\n ");
    f_string_format(1, "                              ----------------------------------------------------------------------------------------");
    printf("\n");

    f_string_format(1, "                              \033[1;38;2;255;25500;255m**********************************************\033[0m");
    f_string_format(1, "                              " cr_w "<  Check Out:                >\033[0m");  // Adjusted spacing
    f_string_format(1, "                              " cr_w "<  Check In:                >\033[0m");
    f_string_format(1, "                              " cr_w "<  Hotel Name:         >\033[0m");
    f_string_format(1, "                              " cr_w "<  Location:                  >\033[0m");
    int b = 21;
    f_string_format(1, "                              " cr_w "<  Booking Date: %d             >\033[0m", b);
    f_string_format(1, "                              " cr_w "<  Commodities:                >\033[0m");
    f_string_format(1, "                              \033[1;38;2;255;25500;255m**********************************************\033[0m");

    printf("\n \n \n \n");
    f_string_format(1, "                              Customer Care:");
    f_string_format(1, "                              email id:");
    f_string_format(1, "                              \u00A9\n");
}
