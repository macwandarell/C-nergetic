#include "../Code_Snippets/String_Alignment/f_string.h"
#include <stdio.h>
int main()
{
    // clear_console();
    print_border("-");
    
    f_string_format(0,"\033[1;38;2;255;165;0mTrivago\033[0m\n");
    char arr[100];
    date_d(arr,sizeof(arr));
    f_string_format(2,"%s",arr);
    print_border("-");
    printf("\n");
    f_string_format(1,"\033[1;38;2;0;100;0mBilling Information\033[0m\n");

    printf("")
    printf("\t");


}