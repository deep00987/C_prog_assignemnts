#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_str_lex(char**, int);
void display(char**, int);

int main(){
    int n, i;
    char *country[100], c;
    printf("\nEnter number of strings to input\n");
    scanf("%d", &n);
    scanf("%c", &c);
    printf("\nEnter strings --\n");
    for (i = 0; i < n; i++){
        country[i] = (char*)malloc(30 * sizeof(char));
        gets(country[i]);
    }
    sort_str_lex(country, n);
    printf("\n-- After sorting --\n");
    display(country, n);
}

void display(char** arr, int n){
    printf("\nThe strings are --\n");
    int i;
    for (i = 0; i < n; i++){
        puts(arr[i]);
    }
}

void sort_str_lex(char** country, int n){
    int i, j, swapped;
    char tmp[60];
    for (i = 0; i < n - 1; i++){
        swapped = 0;
        for (j = 0; j < n - i - 1; j++){
            if (strcmp(country[j], country[j + 1]) > 0){
                strcpy(tmp, country[j]);
                strcpy(country[j], country[j + 1]);
                strcpy(country[j + 1], tmp);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }   
    }
}
