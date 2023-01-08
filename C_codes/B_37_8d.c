#include <stdio.h>
#include <stdlib.h>

typedef long long int big_int;

big_int digit_sum(big_int);

int main(){

    big_int a, res = 0;
    
    printf("\nEnter Number: \n");
    scanf("%lld", &a);
 
    res = digit_sum(a);

    printf("\nSum of the digits of the number: %lld \n", res);
   
    return 0;
}

big_int digit_sum(big_int a){
    if (a == 0){
        return 0;
    }
    return (a % 10) + digit_sum(a / 10);
 
}