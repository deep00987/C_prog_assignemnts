#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display_mat(int**, int, int);
void input_mat(int**, int, int);
int** allocate_memory(int, int);
void merge_2d(int**, int**, int**, int, int, int, int, int, int);
void sort_matrix(int**, int*, int, int, int);
void flat_matrix(int*, int**, int, int);


int main(){
    int **mat1, **mat2, **merged_mat;
    int row1, col1, row2, col2, row3, col3, i, j;

    printf("\nEnter dimentions of the first 2D array\n");
    scanf("%d %d", &row1, &col1);
    
    mat1 = allocate_memory(row1, col1);

    printf("\nEnter dimentions of the first 2D array\n");
    scanf("%d %d", &row2, &col2);


    mat2 = allocate_memory(row2, col2);

    printf("\nEnter elemenets of the first 2D array\n");
    input_mat(mat1, row1, col1);

    printf("\nEnter elemenets of the second 2D array\n");
    input_mat(mat2, row2, col2);


    printf("\nFirst Matrix -----\n");
    display_mat(mat1, row1, col1);
    printf("\nSecond Matrix -----\n");
    display_mat(mat2, row2, col2);

    int total_elements = (row1*col1) + (row2*col2);
    for( i = 1; i <= sqrt(total_elements); i++)
	{
		if(total_elements % i == 0)
		{
			row3 = i;
			col3 = total_elements/i;
		}
	}
    merged_mat = allocate_memory(row3, col3);
    merge_2d(mat1, mat2, merged_mat, row1, col1, row2, col2, row3, col3);

    printf("\nNew matrix dims: %d %d\n", row3, col3);
    printf("\nThe sorted Marged matrix:\n");
    display_mat(merged_mat, row3, col3);   

    return 0;
}

void merge_2d(int **mat1, int **mat2, int **merged_mat, int row1, int col1, int row2, int col2, int row3, int col3){
    int *tmp1, *tmp2, *tmp3, i = 0, j = 0, k = 0, counter;
    int tmp1_size = (row1*col1);
    int tmp2_size = (row2*col2);
    int tmp3_size = tmp1_size + tmp2_size;

    tmp1 = (int*)calloc(tmp1_size, sizeof(int*));
    tmp2 = (int*)calloc(tmp2_size, sizeof(int*));
    tmp3 = (int*)calloc(tmp3_size, sizeof(int*));

    flat_matrix(tmp1, mat1, row1, col1);
    flat_matrix(tmp2, mat2, row2, col2);

    sort_matrix(mat1, tmp1, row1, col1, tmp1_size);
    sort_matrix(mat2, tmp2, row2, col2, tmp2_size);
    
    display_mat(mat1, row1, col1);
    display_mat(mat2, row2, col2);

    while (i < tmp1_size && j < tmp2_size){
        if(tmp1[i] < tmp2[j]){
            tmp3[k++] = tmp1[i++];
        }else{
            tmp3[k++] = tmp2[j++];
        }
    }
    while (i < tmp1_size){
        tmp3[k++] = tmp1[i++];
    }
    while (j < tmp2_size){
        tmp3[k++] = tmp2[j++];
    }

    printf("\n\n");
    for(i = 0; i < tmp3_size; i++){
        printf("%d ", tmp3[i]);
    }

    counter = 0;
    for (i = 0; i < row3; i++){
        for (j = 0; j < col3; j++){
            merged_mat[i][j] = tmp3[counter++];
        }
    }


}

void sort_matrix(int **mat, int* flat_mat, int row, int col, int flat_size){
    //sort
    int i, j, counter, temp = 0;
    int swapped;
    for (i = 0; i < flat_size - 1; i++){
        swapped = 0;
        for(j = 0; j < flat_size - i - 1; j++){
            if (flat_mat[j] > flat_mat[j + 1]){
                temp = flat_mat[j];
                flat_mat[j] = flat_mat[j + 1];
                flat_mat[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
    }
    counter = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            mat[i][j] = flat_mat[counter++];
        }
    }

}

void flat_matrix(int *arr, int** mat, int row, int col){
    // flats a 2d arr into an 1d arr
    int counter, i, j;
    counter = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            arr[counter++] = mat[i][j];
        }
    }
}

int** allocate_memory(int row, int col){
    int** mat;
    int i = 0;
    mat = (int**)calloc(row, sizeof(int*));
    for (i = 0; i < row; i++){
        mat[i] = (int*)calloc(col, sizeof(int));
    }
    return mat;
}

void display_mat(int** mat, int row, int col){
    int i, j;
    printf("\nDisplaying matrix: ---\n");
    for (i = 0; i < row; i++){
        printf("\n");
        for (j = 0; j < col; j++){
            printf("%d  ", mat[i][j]);
        }
    }
}

void input_mat(int** mat, int row, int col){
    int i, j;
    for (i = 0; i < row; i++){
        printf("\n");
        for (j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}