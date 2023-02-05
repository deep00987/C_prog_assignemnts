#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// to successfully compile in linux:
// have to use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_8c.c -o log -lm

int main(){
    int choice;
    double x, result = 0.000000, term;

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


    return 0;
}
