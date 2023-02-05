#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long int big_int;

void dec_to_bin(big_int, char*);

int main(){

    big_int a;
    char res[1024];
    
    printf("\nEnter Number: \n");
    scanf("%lld", &a);

    if(a == 0){
        printf("\nSum of the digits of the number: %d \n", 0);
        exit(1);
    }

    dec_to_bin(a, res);
    printf("\nSum of the digits of the number: %s \n", (res + 1));
   
    return 0;
}

void dec_to_bin(big_int a, char* res){
    if (a == 0){
       strcpy(res, "0");
    }else{
        dec_to_bin(a / 2, res);
        if(a % 2 == 0){
            strcat(res, "0");
        }else{
            strcat(res, "1");
        }
    }
}