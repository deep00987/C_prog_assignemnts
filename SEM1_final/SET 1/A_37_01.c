#include <stdio.h>

int main()
{
    while (1)
    {
        int choice;
        float temp;

        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            printf("%.4f Celsius = %.4f Fahrenheit\n", temp, (temp * 9 / 5) + 32);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            printf("%.4f Fahrenheit = %.4f Celsius\n", temp, (temp - 32) * 5 / 9);
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice");
        }
    }
    return 0;
}