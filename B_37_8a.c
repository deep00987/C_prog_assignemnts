#include <stdio.h>
#include <stdlib.h>

typedef long long int big_int;

big_int fib_memo(int, big_int*);

int main(){
    int n,i;
    big_int *memo;
    big_int res;

    printf("\nEnter nth fibonacci term: \n");
    scanf("%d", &n);

    memo = (big_int*)malloc(sizeof(big_int)*n+1);

    for (i = 0; i < n+1; i++){
        memo[i] = -1;
    }

    memo[0] = 0;
    memo[1] = 1;

    res = fib_memo(n, memo);
    printf("\nThe Nth fibonacci term using memoization: %lld\n", res);

    return 0;
}


big_int fib_memo(int n, big_int* memo){

    if (memo[n] == -1){
        memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    }

    return memo[n];
    
}
