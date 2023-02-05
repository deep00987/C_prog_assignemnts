#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_C 512
char *delim = " ";


void get_input(char**, int*);

int main(){
    char *words[256];   
    int i = 0, char_ascii;
    int word_count;
    int article_count = 0, upper_case_counts = 0;
    printf("\nEnter text:\n");
    
    get_input(words, &word_count);
   
    i = 0;
    
    while (i < word_count){
        //printf("\nWord:  %d: string: %s\n", i, words[i]);

        if (strcmp(words[i], "a") == 0 || strcmp(words[i], "an") == 0 
            || strcmp(words[i], "the") == 0 || strcmp(words[i], "A") == 0 
            || strcmp(words[i], "An") == 0 || strcmp(words[i], "The") == 0
        ){
            printf("\nWord:  %d: string: %s is an article\n", i, words[i]);
            article_count++;
        }
        i++;
    }
    i = 0;
    while (i < word_count){
        //printf("\nWord:  %d: string: %s\n", i, words[i]);

        char_ascii = words[i][0];
        if (char_ascii >= 65 && char_ascii <= 90)
        {
            printf("\nWord:  %d: string: %s is Uppercase\n", i, words[i]);
            upper_case_counts++;
        }
        i++;
    }
    
    printf("\nArticle counts: %d\n", article_count);
    printf("\nUppercase words counts: %d\n", upper_case_counts);

    return 0;
}

void get_input(char **input, int *word_count){
    unsigned ConsecutiveEnterCount = 0;
    int i = 0;
    while(1)
    {   
        fflush(stdin);
        char buffer[256];
        char* token;
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            break; // handle error
        }
        if(buffer[0] == '#'){
            input[i] = (char*)malloc(60 * sizeof(char));
            strcpy(input[i], "#");
            *word_count = i;
            break;
        }
        if (buffer[0] == '\n')
        {
            ConsecutiveEnterCount++;
            if (ConsecutiveEnterCount >= 2)
            {
                *word_count = i;
                break;
            }
        }else{
            ConsecutiveEnterCount = 0;
        }
        
        token = strtok(buffer, delim);

        while (token != NULL){
            //printf("Token: %d, word: %s \n",i, token);
            input[i] = (char*)malloc(60 * sizeof(char));
            strcpy(input[i], token);
            //printf("\ntest: %s\n", input[i]);
            i++;
            token = strtok(NULL, " ");
        }
    }
      
}

