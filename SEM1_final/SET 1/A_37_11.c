#include <stdio.h>
#include<stdlib.h>
#include <math.h>

// windows mingw-64 has some problem printing %Lf type 
// -D__USE_MINGW_ANSI_STDIO=1 flag can be used while compiling in windows env to mitigate this issue but
// fraction part still would show incorrect ans
// The program runs fine and shows correct ans in linux env 
// compiling it in linux  or online c compiler shows corrct answer



typedef double big_double;
// -D__USE_MINGW_ANSI_STDIO=1 
//for windows mingw-64 

big_double fib_formula(int);
big_double fib_memo(int, big_double*);

int main(){
    int n,i;
    big_double *memo;
    big_double res1, res2, diff;

    printf("\nEnter nth fibonacci term: \n");
    scanf("%d", &n);

    memo = (big_double*)malloc(sizeof(big_double)*n+1);

    for (i = 0; i < n+1; i++){
        memo[i] = -1;
    }

    memo[0] = 0.000000;
    memo[1] = 1.000000;

    res1 = fib_formula(n);
    res2 = fib_memo(n, memo);
    
    diff = fabs(res1 - res2);

    printf("\nThe Nth fibonacci term using formula: %Lf\n", res1);
    printf("\nThe Nth fibonacci term using memoization: %Lf\n", res2);
    printf("\nThe difference is: %0.6Lf\n", diff);

    
    return 0;
}


big_double fib_formula(int n){
    big_double res, p1, p2, p3;
    p1 = 1 / sqrt(5);
    p2 = (1 + sqrt(5)) / 2;
    p3 = (1 - sqrt(5)) / 2;
    res = (p1 * pow(p2 , (big_double)n)) - ( p1 * pow(p3, (big_double)n));

    return res;

}

big_double fib_memo(int n, big_double* memo){

    if (memo[n] == -1){
        memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    }

    return memo[n];
    
}
