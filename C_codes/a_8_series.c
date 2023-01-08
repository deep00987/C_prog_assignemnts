#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef long long int big_int;

big_int next_prime(big_int);

int main(){
    int choice;
    double x, result = 0.000000, term;

    
    printf("\nEnter 1, 2, 3, 4, 5 to get series of sin(x), cos(x), log(1+x), e, and 2*3 + 3*5 + 5*7 + ...\n");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("\nEnter the value of x: \n");
            scanf("%lf", &x);
            
            term = x;

            for (int i = 1; i < 250; i++)
            {
                result += term;
                term *= -1 * x * x / (2*i*(2*i+1));
            }
            printf("sin(%f) = %f", x, result);
            break;
        case 2:
            printf("\nEnter the value of x: \n");
            scanf("%lf", &x);

            term = 1.000000;
            for (int i = 0; i < 200; i++)
            {
                result += term;
                term *= -1 * x * x / ((2 * i + 1) * (2 * i + 2));
            }
            printf("cos(%f) = %f", x, result);
            break;
        case 3:
            printf("\nEnter the value of x: \n");
            scanf("%lf", &x);

            term = x;
            for (int i = 1; i < 200; i++)
            {
                if (i % 2 == 0)
                {
                    result -= pow(x, i) / i;
                }
                else
                {
                    result += pow(x, i) / i;
                }
            }
            printf("log(1 + %lf) = %lf", x, result);
            break;
        case 4:
            printf("\nEnter the no of terms: \n");
            scanf("%lf", &x);

            double temp = 1.0000;
            for (int i = 1; i <= x; i++)
            {
                result += (i / temp);

                temp *= (i + 1);
            }
            printf("e = %lf ", result);
            break;
        case 5:
            printf("\nEnter the no of terms: \n");
            scanf("%lf", &x);
            big_int res = 0;
            big_int prev = 2;
            big_int next;
            for (int i = 1; i <= x; i++)
            {
                next = next_prime(prev);
                //printf("\nprev next %lld %lld \n",prev, next);
                res += prev * next;
                prev = next;
                
            }
            printf("res = %lld ", res);
            break;
        default:
            printf("\nExiting.......\n");
            exit(1);

    }

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