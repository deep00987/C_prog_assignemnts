#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// to successfully compile in linux:
// have to use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_8a.c -o sin -lm

int main(){
    int choice;
    double x, result = 0.000000, term;

    printf("\nEnter the value of x: \n");
    scanf("%lf", &x);
            
        term = x;

        for (int i = 1; i < 250; i++)
        {
            result += term;
            term *= -1 * x * x / (2*i*(2*i+1));
        }
        printf("sin(%lf) = %lf", x, result);

    return 0;
}