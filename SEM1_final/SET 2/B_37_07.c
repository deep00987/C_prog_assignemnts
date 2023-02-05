#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len(const char*);
char* str_cpy(char*, const char*);
char* str_cat(char*, const char*);
void str_rev(char*);
int str_cmp(const char*, const char*);
void input_str(char*);

int main(){

    char str1[50], str2[50];
    int choice = 1, tmp;

    // str1 = (char*)malloc(50 * sizeof(char));
    // str2 = (char*)malloc(50 * sizeof(char));

    printf("\npress 1 to get length of a string");
    printf("\npress 2 to copy two strings");
    printf("\npress 3 to concat two strings");
    printf("\npress 4 to reverse a string");
    printf("\npress 5 to compare two strings");
    printf("\npress any other key to exit\n");
    scanf("%d", &choice);
    input_str(str1);
    switch (choice){
        case 1:
            printf("\nEnter the string to get length: \n");
            input_str(str1);
            printf("input str: %s", str1);
            printf("\nstring length: %d\n", str_len(str1));
            break;
        case 2:
            printf("\nEnter the string to be copied: \n");
            input_str(str2);
            printf("input str: %s", str2);
            printf("\ncopied string: %s\n", str_cpy(str1, str2));
            break;
        case 3:
            printf("\nEnter 1st string: \n");
            input_str(str1);
            printf("\nEnter 2st string: \n");
            input_str(str2);
            printf("\ninput str1: %s", str1);
            printf("\ninput str2: %s", str2);
            printf("\nconcated string: %s\n", str_cat(str1, str2));
            break;
        case 4:
            printf("\nEnter the string to be reversed: \n");
            input_str(str1);
            printf("input str: %s", str1);
            str_rev(str1);
            printf("\nreversed string: %s\n", str1);
            break;
         case 5:
            printf("\nEnter 1st string: \n");
            input_str(str1);
            printf("\nEnter 2st string: \n");
            input_str(str2);
            printf("\ninput str1: %s", str1);
            printf("\ninput str2: %s", str2);
            tmp = str_cmp(str1, str2); 
            if (tmp == 0){
                printf("\nBoth strings are equal\n");
            }else if(tmp > 0){
                printf("\nstr1 is lexicographically comes after str2\n");
            }else if(tmp < 0){
                printf("\nstr1 is lexicographically comes before str2\n");
            }
            break;
        default:
            printf("\nExiting ....\n");
            exit(1);
    }

    return 0;
}

void input_str(char* str){
    fflush(stdin);
    gets(str);
    //str[strcspn(str, "\n")] = 0;
}

int str_len(const char* str){
    const char *s;
    for (s = str; *s; ++s);
	return (s - str);
}

char* str_cpy(char* dest, const char *source){
    if (dest == NULL){
        return NULL;
    }
    char* return_ptr = dest;
    while (*dest++ = *source++);
    return return_ptr;
}

char* str_cat(char *dest, const char *source){
    if((dest == NULL) && (source == NULL)){
        return NULL;
    }
    char *return_ptr = dest;
    while  (*dest != '\0'){
        dest++;
    }
    while (*source != '\0'){
        *dest++ = *source++;
    }
    *dest = '\0';
    return return_ptr;
}

void str_rev(char *str){
    int i, j;
    unsigned char ch;
    int len = str_len(str);

    for (i = 0, j = len - 1; i < j; i++, j--){
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }

}

int str_cmp(const char* str1, const char *str2){
    // return 0 if str1 and str2 is equal
    
    // return > 0 when the first non matching char in left str have
    //greater ASCII val then right str i.e left str is lexicographically comes after 
    //right str. 
    
    //return < 0 when the first non matching char in left str have lower ASCII val
    // then the right str i.e left str is lexicographically comes before right str.

    while (*str1 == *str2) {
		if (*str1 == '\0')
			return 0;
		str1++; 
        str2++;
	}
	return *str1 - *str2;
}