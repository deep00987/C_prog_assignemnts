#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_BUFF_SIZE 1024


int check_valid(FILE*, int*);
int count_element(char*);
void display_mat(int**, int, int);
void push_into_matrix(FILE*, int**, int, int);
void row_sum(FILE*, int**, int, int);

int main(){
    FILE* file = fopen("./matrix.txt", "r");
    FILE *file_ptr_2;
    int is_valid_matrix, i;
    int dims[2] = {-1, -1};
    int **bin_matrix;

    is_valid_matrix = check_valid(file, dims);
    
    if(!is_valid_matrix){
        printf("\nThe input matrix has invalid dimantions: ----\n");
        exit(1);
    }

    printf("\nMatrix dimentions are: %d x %d\n", dims[0], dims[1]);

    bin_matrix = (int**)malloc(sizeof(int*) * dims[0]);
    for (i = 0; i < dims[0]; i++){
        bin_matrix[i] = (int*)malloc(sizeof(int) * dims[1]);
    }

    file = fopen("./matrix.txt", "r");
    push_into_matrix(file, bin_matrix, dims[0], dims[1]);
    display_mat(bin_matrix, dims[0], dims[1]);

    file_ptr_2 = fopen("./matrix_row_sum.txt", "w");
    row_sum(file_ptr_2, bin_matrix, dims[0], dims[1]);



    return 0;
}

void row_sum(FILE *file_ptr, int **matrix, int rows, int cols){
    if (file_ptr == NULL){
        printf("\nError opening file\n");
        exit(1);
    }
    char ch, tmp[64], line[256], row_no[10];
    int i = 0, j = 0, sum = 0;
    
    for (i = 0; i < rows; i++){
        sum = 0;
        for (j = 0; j < cols; j++){
            sum += matrix[i][j];
        }
        sprintf(tmp, "%d", sum);
        sprintf(row_no, "%d", i + 1);
        strcpy(line, "Sum of Row ");
        strcat(line, row_no);
        strcat(line, ": ");
        strcat(line, tmp);
        strcat(line, "\n");
        printf("%s\n", line);
        fputs(line, file_ptr);
    }
    
    fclose(file_ptr);
}


int check_valid(FILE* file_ptr, int *dims){

    if (file_ptr == NULL){
        return FALSE;
    }
    int ch_index = 0, curr_row_ele, line_no = 0;
    int row_elements;
    char ch, line[MAX_BUFF_SIZE];

    while (ch = fgetc(file_ptr)){
        if (ch_index >= MAX_BUFF_SIZE){
            printf("Error max line size reached!");
            return FALSE;
        }
        if (ch == EOF){
            line_no += 1;
            line[ch_index] = '\0';
            fprintf(stdout, "%s", line);
            curr_row_ele = count_element(line);
            printf("\trow items:  %d\n", curr_row_ele);

            if (row_elements != curr_row_ele){
                // printf("row legth mismatch!:  %s", line);
                return FALSE;
            }
            break;
        }else if (ch == '\n') {
            line_no += 1;
            line[ch_index] = '\0';
            ch_index = 0;
            fprintf(stdout, "%s", line);
            curr_row_ele = count_element(line);
            printf("\trow items:  %d\n", curr_row_ele);
            if (line_no == 1){
                row_elements = curr_row_ele;
            }
            if (row_elements != curr_row_ele){
                // printf("row legth mismatch!:  %s", line);
                return FALSE;
            }
            continue;
        }else{
            line[ch_index++] = ch;
        }
    }
    // printf("\nNo of lines: (rows) %d\n", line_no);
    // printf("no of elemenets: (cols) %d", row_elements);
    dims[0] = line_no;
    dims[1] = row_elements;
    fclose(file_ptr);
    return TRUE;

}

void push_into_matrix(FILE *file_ptr, int** matrix, int rows, int cols){
    if (file_ptr == NULL){
        printf("\nError opening file\n");
        exit(1);
    }
    char ch;
    int i = 0, j = 0;
    while ((ch = fgetc(file_ptr)) != EOF){
        printf("%c", ch);
        if (ch != '0' && ch != '1'){
            continue;
        }
        
        if (j == cols){
            i += 1;
            j = 0;
        }
        matrix[i][j] = ch - '0';
        j ++;
    }
    
    fclose(file_ptr);
}


void display_mat(int** matrix, int m, int n){
    int i , j;
    printf("\nElements in the matrix are ---->\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int count_element(char *line){
    char *temp = line;
    int ele = 0;
    while (*temp != '\0'){
        if (*temp == '0' || *temp == '1'){
            ele ++;
        }
        temp++; 
    }
    return ele;
}