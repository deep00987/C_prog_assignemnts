#include <stdio.h>
#include <stdlib.h>

typedef long long int big_int;

big_int gcd(big_int, big_int);

int main(){

    big_int a, b, res = 0;
    int flag = 0;
 
    printf("\nEnter two number to get GCD: \n");
    scanf("%lld %lld", &a, &b);
 
    res = gcd(a, b);

    if (res != -1){
        printf("\nResult of GCD: %lld \n", res);
    }

    return 0;
}

big_int gcd(big_int a, big_int b){
    if (a == 0 && b == 0){
        printf("\nResult of GCD: INFINITY\n");
        return -1;
    }
 
    printf("\nsteps: %lld %lld\n", a , b);
 
    if (b == 0){
        return a;
    }

    return gcd(b, a % b);
 
}