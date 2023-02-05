#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// to successfully compile in linux:
// have to use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_8b.c -o cos -lm

int main(){
    int choice;
    double x, result = 0.000000, term;

    printf("\nEnter the value of x: \n");
    scanf("%lf", &x);

    term = 1.000000;
    for (int i = 0; i < 200; i++)
    {
        result += term;
        term *= -1 * x * x / ((2 * i + 1) * (2 * i + 2));
    }
    printf("cos(%f) = %f", x, result);
    

    return 0;
}

