#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// to successfully compile in linux:
// have to use use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_8e.c -o next_prime -lm

// The result of test case no. 3 and 4 is wrong in the question paper as confirmed in class 


typedef long long int big_int;
big_int next_prime(big_int);

int main(){
    int choice;
    double x, result = 0.000000, term;


    printf("\nEnter the no of terms: \n");
    scanf("%lf", &x);
    big_int res = 0;
    big_int prev = 2;
    big_int next;
    for (int i = 1; i <= x; i++)
    {
        next = next_prime(prev);
        // printf("\nprev next %lld %lld \n",prev, next);
        res += prev * next;
        prev = next;
    }
    printf("res = %lld ", res);

    return 0;
}

big_int next_prime(big_int prev)
{
    big_int next = prev + 1;
    while (1)
    {
        int flag = 1;
        for (big_int i = 2; i <= sqrt(next); i++)
        {
            if (next % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return next;
        }
        next++;
    }
}