#include <stdio.h>

int main()
{
    int exp;
    float base, result = 1.0;
    printf("Enter base number: ");
    scanf("%f", &base);
    printf("Enter exp: ");
    scanf("%d", &exp);
    
    if (base == 0 && exp <= 0)
    {
        printf("undefined");
    }
    
    else if (exp < 0)
    {
        exp = -exp;
        while (exp != 0)
        {
            result *= base;
            --exp;
        }
        result = 1 / result;
        printf("%.4f", result);
    }
    
    else
    {
        while (exp != 0)
        {
            result *= base;
            --exp;
        }
        printf("%f", result);
    }
}