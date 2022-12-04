#include <stdio.h>
#include <stdlib.h>

void get_max_min(int*, int);
void display(int*, int);

int main(){
    int *arr, n, i;
    
    printf("\nEnter the number of elements: \n");
    scanf("%d", &n);

    arr = malloc(sizeof *arr * n);

    printf("\nEnter the array elements: \n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    display(arr, n);
    get_max_min(arr, n);


    return 0;
}

void get_max_min(int *arr, int n){
    int upper, lower, curr_max, i, k;
    lower = INT_MIN;
    upper = INT_MAX;
    curr_max = 0;
    for (k = 0; k < 4; k++){
        lower = INT_MIN;
        for (i = 0; i < n; i++){
            if (arr[i] > lower && arr[i] < upper){
                lower = arr[i];
                
            }
        }
        curr_max = lower;
        upper = lower;
    }

    printf("\n3rd highest: %d", curr_max);


}

void display(int *arr, int n) {   
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}