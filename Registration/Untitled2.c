#include <stdio.h>

int main(){
    int a,k,r;
    printf("Enter the number of adults: ");
    scanf("%d",&a);
    //getchar();
    printf("Enter the number of kids: ");
    scanf("%d",&k);
    printf("Enter the number of rooms needed: ");
    scanf("%d",&r);
    //getchar();
    int r1 =0;
    if(a%2==0){
        r1+=a/2;
        if(k>r1){
            if((k-r1)%3==0) r1+=(k-r1)/3;
            else r1+=(k-r1)/3 + 1;
        }
    }
    else{
        r1+=a/2 + 1;
        if(k>r1){
            if((k-r1-1)%3==0){
            r1+=(k-r1-1)/3;}
            else r1+=(k-r1-1)/3 + 1;
        }
    }
    printf("Minimum number of rooms needed are %d\n",r1);
    if(r<r1){
        printf("Sorry you need to book %d more rooms to accomodate everyone.",r1-r);
    }
    else printf("Congratulations, your rooms have been booked successfully!!!!");
}
