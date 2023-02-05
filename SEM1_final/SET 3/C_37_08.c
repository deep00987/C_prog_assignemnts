#include <stdio.h>
#include <stdlib.h>
 
void input_into_file(FILE*);
void show_file_contents(FILE*);
void to_upper(FILE*, FILE*);
int main(){
    FILE *file_ptr, *file_ptr_2;
    file_ptr = fopen("./c_37_08_file.txt", "r");
    file_ptr_2 = fopen("./c_37_08_file_upper.txt", "w");
    // input_into_file(file_ptr);
    // show_file_contents(file_ptr);
    to_upper(file_ptr, file_ptr_2);
    // show_file_contents(file_ptr);
   
    return 0;
}
 
void input_into_file(FILE *file_ptr){
    char input[1024], *hack;
    // input = (char*)malloc(sizeof(char)*256);
    if (file_ptr == NULL){
        printf("\nError occured opening file\n");
        return;
    }
    // scanf("%c", &hack);
    printf("\nEnter content to store in to the file -----\n");
    fgets(input, sizeof(input), stdin);
    fputs(input, file_ptr);
    fclose(file_ptr);
}
 
void show_file_contents(FILE *file_ptr){
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
 
void to_upper(FILE *file_ptr, FILE* file_ptr_2){
    if (file_ptr == NULL || file_ptr_2 == NULL){
        printf("\nError occured opening file\n");
        return;
    }
    char ch;
    // int i = 0;
    while ((ch = fgetc(file_ptr)) != EOF){
       
        if ((ch > 96) && (ch < 123)){
            // temp[i] = ch - 32;
            fputc(ch - 32, file_ptr_2);
        }else{
            // temp[i] = ch;
            fputc(ch, file_ptr_2);
        }
        // printf("%c", ch);
    }
    // temp[i] = '\0';
    // puts(temp);
    fclose(file_ptr);
    fclose(file_ptr_2);
 
    // file_ptr = fopen("./c_37_08_file_upper.txt", "w");
   
    // if (file_ptr == NULL){
    //     printf("\nError occured opening file\n");
    //     return;
    // }
    // fputs(temp, file_ptr);
    // fclose(file_ptr);
 
}