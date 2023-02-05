#include <stdio.h>
 
long get_gcd_euclid(long, long);
long get_gcd_factor(long, long);
int main(){
 
    long a, b, res = 0, res2 = 0;
    int flag = 0;
 
    printf("\nEnter two number to get GCD: \n");
    scanf("%ld %ld", &a, &b);
 
    res = get_gcd_euclid(a, b);
 
    if (res != -1){
        printf("\nResult using Euclid: %ld \n", res);
    }
    res2 = get_gcd_factor(a, b);
    if(res2 != -1){
        printf("\nResult using Factor: %ld \n", res2);
    }
    return 0;
}
 
long get_gcd_euclid(long a, long b){
    if (a == 0 && b == 0){
        printf("\nResult using Euclid: INFINITY\n");
        return -1;
    }
 
    printf("\nsteps: %ld %ld\n", a , b);
 
    if (b == 0){
        return a;
    }
 
    return get_gcd_euclid(b, a % b);
 
}
 
long get_gcd_factor(long a, long b){
    printf("\nFactorization method ...\n");
    if (a == 0 && b == 0){
        printf("\nResult using Factor: INFINITY\n");
        return -1;
    }
    long res = 1;
    
    if (b == 0){
        return a;
    }

    long a1 = a;
    long b1 = b;
    
    for (int i = 2; i <= b1; i++)
    {
        while (a1 % i == 0 && b1 % i == 0)
        {
            printf("steps: %d < %ld , %ld >\n", i, a1, b1);
            res *= i;
            a1 /= i;
            b1 /= i;
        }
    }
    printf("  | %ld , %ld \n", a1, b1);
    printf("\nresult: %ld\n", res);
    return res;
 
}