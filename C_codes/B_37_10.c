#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_sub_str(char*, char*);


int main(){
    char *str1, *str2, c;
    int m, n, res;

    printf("\nEnter size of the first string: \n");
    scanf("%d", &m);
    printf("\nEnter size of the second string: \n");
    scanf("%d", &n);
    scanf("%c", &c);
    str1 = (char*)malloc(m * sizeof(char));
    str2 = (char*)malloc(n * sizeof(char));

    printf("\nEnter the first string: \n");
    gets(str1);
    printf("\nEnter the second string: \n");
    gets(str2);


    if (*str1 == '\0' || *str1 == '\n'){
        printf("source string is not given");
        exit(1);
    }

    if (*str2 == '\0' || *str2 == '\n'){
        printf("Substring is not given to check");
        exit(1);
    }


    res = check_sub_str(str1, str2);

    if (res == 0){
        printf("\nSubstring is not present.\n");
    }else{
        printf("\nSubstring present starting at index %d\n", res);
    }

    return 0;
}

int check_sub_str(char *str1, char *str2){
    
    int size_1 = 0, size_2 = 0, i, j, flag;

    while (str1[size_1] != '\0'){
        size_1++;
    }
    while (str2[size_2] != '\0'){
        size_2++;
    }

    for (i = 0; i <= size_1 - size_2; i++){
        for (j = i; j < i + size_2; j++){
            flag = 1;
            if (str1[j] != str2[j - i]){
                flag = 0; 
                break;
            }
        }
        if (flag == 1){
            return i;
        }
    }

    return 0;
}