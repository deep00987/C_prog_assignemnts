#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 
void display_mat(int**, int);
void display_arr(int*, int);
void matrix_sum_diff(int**, int**,int**, int**, int);
 
int main(){
    int ip[100], even_arr[100], odd_arr[100];
    int **even_mat, **odd_mat, **sum_mat, **diff_mat;
    int n, i, j, k, even = 0, odd = 0, s_even, s_odd, square_dim;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
 
    for (i = 0; i < n; i++){
        scanf("%d", &ip[i]);
    }
    j = 0;
    k = 0;
    for (i = 0; i < n; i++){
        if (ip[i] % 2 == 0){
            even_arr[j] = ip[i];
            even++;
            j++;
        }else{
            odd_arr[k] = ip[i];
            k++;
            odd++;
        }
    }
 
    printf("\neven count: %d", even);
    printf("\nodd count: %d", odd);
    
    if (even < 4 || odd < 4){
        printf("\nMatrix creation not possible\n");
        exit(1);
    }

    printf("\nEven num Array:\n");
    display_arr(even_arr, even);
    printf("\nOdd num Array:\n");
    display_arr(odd_arr, odd);
 
    //get square martrix dimention m x m
    s_even = floor(sqrt(even));
    s_odd = floor(sqrt(odd));
    square_dim = s_even > s_odd ? s_odd : s_even;
   
    //allocate memory to new marices
   
    even_mat = (int**)malloc(sizeof(int *) * square_dim);
    odd_mat = (int**)malloc(sizeof(int *) * square_dim);
    sum_mat = (int**)malloc(sizeof(int *) * square_dim);
    diff_mat = (int**)malloc(sizeof(int *) * square_dim);
 
 
    for(i = 0; i< square_dim; i++) {
        even_mat[i] = (int*)malloc(sizeof(int) * square_dim);
        odd_mat[i] = (int*)malloc(sizeof(int) * square_dim);
        sum_mat[i] = (int*)malloc(sizeof(int) * square_dim);
        diff_mat[i] = (int*)malloc(sizeof(int) * square_dim);
    }
    // insert elements into matrices
    k = 0;
    for (i = 0; i < square_dim; i++){
        for (j = 0; j < square_dim; j++)
        {
            even_mat[i][j] = even_arr[k];
            k++;
        }
       
    }
 
    k = 0;
    for (i = 0; i < square_dim; i++){
        for (j = 0; j < square_dim; j++)
        {
            odd_mat[i][j] = odd_arr[k];
            k++;
        }
       
    }
    // print and do operations in the matrices
    printf("\nEven Matrix:\n");
    display_mat(even_mat, square_dim);
    printf("\nOdd Matrix:\n");
    display_mat(odd_mat, square_dim);
    matrix_sum_diff(even_mat, odd_mat, sum_mat, diff_mat, square_dim);
    printf("\nAfter addition: \n");
    display_mat(sum_mat, square_dim);
    printf("\nAfter subtraction: \n");
    display_mat(diff_mat, square_dim);
    
    //free memory
    for (i = 0; i < square_dim; i++){  
       free(even_mat[i]);
       free(odd_mat[i]);
       free(sum_mat[i]);  
       free(diff_mat[i]);
    }    
    free(even_mat);
    free(odd_mat);
    free(sum_mat);  
    free(diff_mat);


    return 0;
}
 
void display_arr(int *arr, int n){
    int i = 0;
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
 
 
void display_mat(int **mat,int n){
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
 
void matrix_sum_diff(int **even, int **odd, int **sum, int **diff, int square_dim) {
    int i,j;
    for(i = 0; i < square_dim; i++) {
        for(j = 0; j < square_dim; j++){
            sum[i][j] = even[i][j] + odd[i][j];
            diff[i][j] = even[i][j] - odd[i][j];
        }
    }
 
}