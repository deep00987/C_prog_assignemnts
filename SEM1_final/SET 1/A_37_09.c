#include <stdio.h>
#include <math.h>

// to successfully compile in linux:
// have to use use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_09.c -o prime -lm

typedef long long int big_int;

int is_prime(big_int);

int main(){
    big_int n, i;
    int flag = 0;
    printf("\nEnter the range: \n");
    scanf("%lld", &n);

    for (i = 1; i < n; i++){
        if(is_prime(i) == 1){
            flag = 1;
            printf("%lld\t", i);
        }
    }
    if(flag == 0){
        printf("\nNo prime numbers are presant\n");
    }
    printf("\n\n");
    return 0;
}

int is_prime(big_int n){
    big_int i;
    if (n == 0 || n == 1){
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}