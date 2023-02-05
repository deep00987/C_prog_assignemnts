#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char* get_reverse(char*);

int main(){
    char* ip;
    char *index_ptr, *ip_trimmed, *op_reverse;
    ip = (char*)malloc(MAX_SIZE*sizeof(char));
    printf("\nEnter the number: \n");
    scanf("%s", ip);


    index_ptr = ip;

    while (*index_ptr != '\0') {
        if (*index_ptr == '0'){
            index_ptr++;
        }else{
            break;
        }
    } 
    // trimmed input string and reversed string in case of leading zeros 
    ip_trimmed = index_ptr;
    op_reverse = get_reverse(ip_trimmed);
    
    printf("\nInput number: ");
    puts(ip);
    printf("\nReversed number: ");
    puts(op_reverse);

    if (strlen(ip_trimmed) != strlen(op_reverse)){
        printf("\nThe number is not a palindrome!\n");
        exit(1);
    }

    while (*ip_trimmed != '\0'){
        if (*ip_trimmed != *op_reverse){
            printf("\nThe number is not a palindrome!\n");
            exit(1);
            
        }
        ip_trimmed++;
        op_reverse++;
    }

    printf("\nThe number is a palindrome!\n");
    
    

    return 0;

}

char* get_reverse(char* index_ptr){
    char* op = (char*)malloc(MAX_SIZE*sizeof(char));
    char* start = index_ptr;
    int i = 0;
    while (*index_ptr != '\0'){
        index_ptr++;
    }
    index_ptr--;
    while (index_ptr != start){
        *(op + i) = *index_ptr;
        index_ptr--;
        i++;
    }
    *(op + i) = *start;
    *(op + i + 1) = '\0';

    while(*op != '\0'){
        if (*op == '0'){
            op++;
        }else{
            break;
        }
    }
    return op;
}


