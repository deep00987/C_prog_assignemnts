#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *ones[20] = {"", "one ", "two ", "three ", "four ",
                    "five ","six ", "seven ","eight ",    "nine ",
                    "ten ",     "eleven ",  "twelve ",    "thirteen ", "fourteen ",
                    "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };


char *tens[10] = { "", "", "twenty ",  "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

char* num_to_word_two_digit(int);
char* num_to_word_three_digit(int);
void print_indian(int);
void print_international(int);
int main(){
    long n;
    char res[100]; 
   
    printf("\nEnter any number of 8 digits or less: \n");
    scanf("%ld", &n);

    print_indian(n);
    print_international(n);
    
    return 0;
}

char* num_to_word_two_digit(int n){
    char *str = (char*)malloc(sizeof(char)*100);
    char word1[100], word2[100];
    int q, r;
    if (n < 20){
        return ones[n];
    }
    q = n / 10;
    r = n % 10;

    strcpy(word1, tens[q]);
    strcpy(word2, ones[r]);
    strcat(word1, word2);
    strcpy(str, word1);
    
    return str;
}

char* num_to_word_three_digit(int n){
    char *str = (char*)malloc(sizeof(char)*100);

    char word1[100], word2[100];
    int q, r;
    if (n < 100){
        return num_to_word_two_digit(n);
    }
    q = n / 100;
    r = n % 100;

    strcpy(word1, ones[q]);
    strcat(word1, "hundred ");
    strcpy(word2, num_to_word_two_digit(r));
    strcat(word1, word2);
    strcpy(str, word1);
    // printf("\nNumber in words: %s\n", word1);
    // strcat(res, word2);
    return str;
}

void print_indian(int n){
    char *result = (char*)malloc(sizeof(char)*255);
    strcpy(result, num_to_word_two_digit(n/10000000));
    if (num_to_word_two_digit(n/10000000) != ""){
        strcat(result, "crore ");
    }
    n = n % 10000000;
    //print lakhs   
    strcat(result, num_to_word_two_digit(n/100000));
    if (num_to_word_two_digit(n/100000) != ""){
        strcat(result, "lakh ");
    }
    n = n % 100000;
    //print thousands
    strcat(result, num_to_word_two_digit(n/1000));
    if (num_to_word_two_digit(n/1000) != ""){
        strcat(result, "thousand ");
    }
    n = n % 1000;  
    //print hundreds  
    strcat(result, num_to_word_two_digit(n/100));
    if (num_to_word_two_digit(n/100) != ""){
        strcat(result, "hundred ");
    }
    n = n % 100;
    //print remaninder
    strcat(result, num_to_word_two_digit(n));
    printf("\nNumber in words indian: %s\n", result);
}

void print_international(int n){
    char *result = (char*)malloc(sizeof(char)*255);
    //print million   
    strcpy(result, num_to_word_two_digit(n/1000000));
    if (num_to_word_two_digit(n/10000000) != ""){
        strcat(result, "million ");
    }
    n = n % 1000000;
    //print thousands   
    strcat(result, num_to_word_three_digit(n/1000));
    if (num_to_word_three_digit(n/1000) != ""){
        strcat(result, "thousand ");
    }
    n = n % 1000;
    //print remaninder
    strcat(result, num_to_word_three_digit(n));
    printf("\nNumber in words international: %s\n", result);

}