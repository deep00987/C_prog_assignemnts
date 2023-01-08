#include <stdio.h>
#include <stdlib.h>


void display_mat(long**, int, int);
void matrix_mult(long**, long**,long**, int, int, int, int);
void matrix_trans(long**, long**, int, int);
void check_orthogonal(long**, long**, int, int, int, int);
long** allocate_memory(int, int);

int main(){
    long **mat, **trans, **product;
    int row1, col1, row2, col2, i, j;

    printf("\nEnter dimentions of the matrix\n");
    scanf("%d %d", &row1, &col1);
    row2 = col1;
    col2 = row1;

    mat = allocate_memory(row1, col1);
    trans = allocate_memory(row2, col2);
    product = allocate_memory(row1, col2);


    printf("\nEnter elemenets of the matrix\n");
    for (i = 0; i < row1; i++){
        for (j = 0; j < col1; j++){
            scanf("%ld", &mat[i][j]);
        }
    }
    printf("\nFirst Matrix -----\n");
    display_mat(mat, row1, col1);

    printf("\nAfter transpose of M --> T(M) -----\n");
    matrix_trans(trans, mat, row1, col1);
    display_mat(trans, col1, row1);

    printf("\nAfter multiplication of M * T(M) -----\n");
    matrix_mult(product, mat, trans, row1, col1, row2, col2);
    display_mat(product, row1, col2);
    
    //cheack if matrix is orthogonal or not

    if (row1 != col1){
        printf("\nThe input matrix is not orthogonal\n");
        exit(1);
    }

    for (i = 0; i < row1; i++){
        for (j = 0; j < col2; j++){
            if (i != j && product[i][j] != 0){
                printf("%d %d %ld",i, j, mat[i][j]);
                printf("\nThe input matrix not orthogonal\n");
                exit(1);
            }
            else if ( i == j && product[i][j] != 1){
                printf("\nThe input matrix not orthogonal\n");
                exit(1);
            }
        }
    }

    printf("\nThe input matrix is orthogonal\n");

    return 0;
}

void matrix_trans(long** trans, long** mat, int rows, int cols){
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            trans[j][i] = mat[i][j];
        }
    }
}

void matrix_mult(long** product,long **mat, long** trans, int row1, int col1, int row2, int col2){
    int i, j, k;
    for (i = 0; i < row1; i++){
        for (j = 0; j < col2; j++){
            product[i][j] = 0;
            for (k = 0; k < col1; k++){
                product[i][j] +=  mat[i][k] * trans[k][j];
            }
        }
    }
}

long** allocate_memory(int row, int col){
    long** mat;
    int i = 0;
    mat = (long**)calloc(row, sizeof(long*));
    for (i = 0; i < row; i++){
        mat[i] = (long*)calloc(col, sizeof(long));
    }
    return mat;
}

void display_mat(long** mat, int row, int col){
    int i, j;
    printf("\nDisplaying matrix: ---\n");
    for (i = 0; i < row; i++){
        printf("\n");
        for (j = 0; j < col; j++){
            printf("%ld  ", mat[i][j]);
        }
    }
}

