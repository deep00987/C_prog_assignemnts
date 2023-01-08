#include <stdio.h>
#include <stdlib.h>

void display(int*, int);
void permutation(int*, int, int);

int main(){
    int a[] = {1, 2, 3};
    int n = sizeof a / sizeof a[0];
    permutation(a, n, n);
    return 0;
}

void display(int *arr, int n) {   
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void permutation(int *arr, int curr_size, int size){
    int i = 0, temp;
    if (curr_size == 1){
        display(arr, size);
        return;
    }

    for (i = 0; i < curr_size; i++){
        permutation(arr, curr_size - 1, size);
        if (curr_size % 2 == 0){
            temp = arr[i];
            arr[i] = arr[curr_size - 1];
            arr[curr_size - 1] = temp;
        }else{
            temp = arr[0];
            arr[0] = arr[curr_size - 1];
            arr[curr_size - 1] = temp;
        }

    }
}