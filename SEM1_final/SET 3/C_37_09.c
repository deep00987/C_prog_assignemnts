#include <stdio.h>
#include <stdlib.h>
 
void input_file_contents(FILE*);
void display_file_contents(FILE*);
void append_into_file(FILE*, FILE*);
int main(){
    FILE *file_ptr_1, *file_ptr_2;
    // file_ptr_1 = fopen("./C_37_09_file_1.txt", "w");
    // file_ptr_2 = fopen("./C_37_09_file_2.txt", "w");
 
    // input_file_contents(file_ptr_1);
    // input_file_contents(file_ptr_2);
 
    // file_ptr_1 = fopen("./C_37_09_file_1.txt", "r");
    // file_ptr_2 = fopen("./C_37_09_file_2.txt", "r");
 
    // display_file_contents(file_ptr_1);
    // display_file_contents(file_ptr_2);

    file_ptr_1 = fopen("./c_37_09_file_1.txt", "a");
    file_ptr_2 = fopen("./c_37_09_file_2.txt", "r");
 
    append_into_file(file_ptr_1, file_ptr_2);
 
    // file_ptr_1 = fopen("./C_37_09_file_1.txt", "r");
    // display_file_contents(file_ptr_1);
 
    return 0;
}
 
void input_file_contents(FILE* file_ptr){
    char input[256], *hack;
    if (file_ptr == NULL){
        printf("\nError occured opening file\n");
        return;
    }
    printf("\nEnter content to store in to the file -----\n");
    fgets(input, sizeof(input), stdin);
    fputs(input, file_ptr);
    fclose(file_ptr);
}
 
void display_file_contents(FILE *file_ptr){
    if (file_ptr == NULL){
        printf("\nError occured opening file\n");
        return;
    }
    char ch;
    while ((ch = fgetc(file_ptr)) != EOF){
        printf("%c", ch);
    }
    fclose(file_ptr);
}
 
void append_into_file(FILE *file_ptr_1, FILE *file_ptr_2){
    
    if (file_ptr_1 == NULL  || file_ptr_2 == NULL){
        printf("\nError occured opening file\n");
        return;
    }
 
    char ch;
    while ((ch = fgetc(file_ptr_2)) != EOF){
        fputc(ch, file_ptr_1);
    }
    // temp[i] = '\0';
    fclose(file_ptr_2);
    fclose(file_ptr_1);
}