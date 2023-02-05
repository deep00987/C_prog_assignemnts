#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long int big_int;

int dec_to_base_x(big_int, int, char*, int);

int main(){

    big_int a;
    int base, index;
    char res[1024];
    
    printf("\nEnter Number: \n");
    scanf("%lld", &a);

    printf("\nEnter base to convert: \n");
    scanf("%d", &base);

    if(a == 0){
        printf("\nSum of the digits of the number: %d \n", 0);
        exit(1);
    }

    index = dec_to_base_x(a, base, res, 0);
    res[index] = '\0';
    strrev(res);
    printf("\nSum of the digits of the number: %s \n", res);
   
    return 0;
}

int dec_to_base_x(big_int a, int base, char* res, int index){
    if (a == 0){
       //strcpy(res, "0");
       if(a > 9){
            printf("%c", (55 + a));
            res[index] = (55 + a);
       }else{
            printf("%c", (48 + a));
            res[index] = (48 + a);
       }
       return index;
    }else{
        int x;
        x = dec_to_base_x(a / base, base, res, index + 1);
        if(a % base > 9){
            printf("%c", (55 + a % base));
            res[index] = (55 + a % base);
        }else{
            printf("%c", (48 + a % base));
            res[index] = (48 + a % base);
        }
        return x;
    }
}