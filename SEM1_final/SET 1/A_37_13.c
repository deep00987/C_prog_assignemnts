#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// to successfully compile in linux:
// have to use -lm flag while compiling to link math.h and use functions in math.h
// example: gcc A_37_13.c -o matrix -lm

void display_mat(double**, int);
void display_vector(double**, int );

int main(){
    double **M, **R, **result;
    int n, i, j, k, power;
    double rand_sum, temp_sum;
    printf ("\nEnter the dimension of trhe square matrix\n");
    scanf("%d", &n);
    printf ("\nEnter the power\n");
    scanf("%d", &power);

    //allocate memory to M
    M = (double**)malloc(n * sizeof(double*));
    R = (double**)malloc(n * sizeof(double*));
    result = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++){
        M[i] = (double*)malloc(n * sizeof(double));
        R[i] = (double*)malloc(1 * sizeof(double));
        result[i] = (double*)calloc(1, sizeof(double));
    }

    srand(time(NULL));

    for (i = 0; i < n; i++){
        rand_sum = 0.000000;
        for(j = 0; j < n; j++){
            M[i][j] = rand() % 100;
            rand_sum += M[i][j];
        }
        for(j = 0; j < n; j++){
            M[i][j] = (M[i][j] / rand_sum) * 1.0;
        }

    }

    for (i = 0; i < n; i++){
        R[i][0] = 1.0/n;
    }
    printf("\nInput matrix M: \n");
    display_mat(M, n);
    printf("\ncolumn vector R: \n");
    display_vector(R, n);
    printf("\nBefore calculation new Vector: \n");
    display_vector(result, n);
    //opeartions

    while (power > 0){
        //(M^p)R = (M x (M x (M....(M x (M x (M x R)))....)))
        //result = M x R
        for (i = 0; i < n; i++)
        {
            temp_sum = 0;
            for (j = 0; j < n; j++)
            {
                temp_sum += (M[i][j] * R[j][0]);
            }
            result[i][0] = temp_sum;
        }
        //R = M x R for each iteration
        for (i = 0; i < n; i++){
            R[i][0] = result[i][0];
        }

        power--;
    }

    printf("\nAfter calculation new Vector: \n");
    display_vector(result, n);


    return 0;
}

void display_mat(double** arr, int n){
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%0.6f  ", arr[i][j]);
        }
        printf("\n");
    }

}

void display_vector(double** arr, int n){
    int i, j;

    for(i = 0; i < n; i++){
        printf("%0.6f  ", arr[i][0]);
        
    }

}