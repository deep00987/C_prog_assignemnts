#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// to successfully compile in linux:
// have to use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_8d.c -o exp -lm

int main(){
    int choice;
    double x, result = 0.000000, term;


    printf("\nEnter the no of terms: \n");
    scanf("%lf", &x);

    double temp = 1.000000;
    for (int i = 1; i <= x; i++)
    {
        result += (i / temp);

        temp *= (i + 1);
    }
    printf("e = %lf ", result);

    return 0;
}