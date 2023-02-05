#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_string(char**,  char*, int*);
void reverse_words_iter(char**, int);
void reverse_words_rec(char**, int, int);
void reverse_str_iter(char*);
void reverse_str_rec(char*);

int main(){
    char input_str[256];
    char tmp_str[256];
    char *words[256];
    int word_count;

    printf("\nEnter string: \n");
    fgets(input_str, 256, stdin);
    input_str[strcspn(input_str, "\n")] = 0;

    strcpy(tmp_str, input_str);

    split_string(words, tmp_str, &word_count);
    printf("IP string: %s", input_str);
    printf("\n\n");

    reverse_str_iter(input_str);
    printf("\nThe string in reverse using recursive method:\n");
    reverse_str_rec(input_str);
    
    printf("\n\n");
    reverse_words_iter(words, word_count);
    printf("\nThe string in reverse using recursive method:\n");
    reverse_words_rec(words, 0, word_count);

    return 0;
}

void split_string(char** words, char* input_str, int *word_count){
    int i = 0;
    char* token;
    token = strtok(input_str, " ");

    while (token != NULL)
    {
        // printf("Token: %d, word: %s \n",i, token);
        words[i] = (char *)malloc(60 * sizeof(char));
        strcpy(words[i], token);
        // printf("\ntest: %s\n", input[i]);
        i++;
        token = strtok(NULL, " ");
    }
    *word_count = i;
}

void reverse_str_iter(char* str){
    char *index = str;
    char *start = str;
    int i = 0;
    while (*(index + i) != '\0'){
        index++;
    }
    printf("\nThe string in reverse using iterative method:\n");
    while (index != start){
        printf("%c", *index);
        index--;
    }
    printf("%c", *(start));
    
}

void reverse_str_rec(char* str){
    if (*str == '\0'){
        return;
    }else{
        reverse_str_rec(str + 1);
        printf("%c", *str);
    }
    
}

void reverse_words_iter(char** str, int n){
    int i;
    printf("\nThe string in reverse by words using iterative method:\n");
    for (i = n - 1; i > -1; i--){
       printf("%s ", str[i]);
    }
}

void reverse_words_rec(char** str, int i, int n){
    if (i < n){
        reverse_words_rec(str, i + 1, n);
        printf("%s ", str[i]);
    }else{
        return;
    }
}
