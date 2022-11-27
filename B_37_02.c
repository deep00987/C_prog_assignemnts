#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef long int big_int;

/*
    Write a function named random partition() which will accept an 1-D array as input and
    randomly choose one of the array elements as X and partition the array into two parts
    where one part contains all elements less than X and another parts contain all elements
    greater than X. Do it without sorting the list.
*/
void partition(big_int*, int);
void display_arr(big_int*, int);
big_int swap(big_int*, big_int*);

int main(){
    srand(time(NULL));
    big_int* arr;
    int n, i;
    printf("\nEnter the size of the array: \n");
    scanf("%d", &n);
    arr = (big_int*)calloc(n, sizeof(big_int));

    printf("\nEnter the elements in the array\n");
    for (i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
    }

    display_arr(arr, n);
    partition(arr, n);
    
    return 0;
}

void display_arr(big_int* arr, int n){
    printf("\n");
    int i = 0;
    for (i = 0; i < n; i++){
        printf("%ld  ", arr[i]);
    }

}

void partition(big_int *arr, int n){
    int rand_index = 0, size1, size2, i, counter = 0;
    big_int pivot;
    big_int *p1, *p2;
    rand_index = (rand() % ( (n - 1) - 0 + 1)) + 0;
    printf("\nRandom index: %d, Pivot element: %ld\n", rand_index, arr[rand_index]);

    int low = 0, high = n - 1;
    swap(&arr[rand_index], &arr[0]);
    pivot = arr[0];

    while (low < high){
        while (arr[low] <= pivot){
            low++;
        }
        while (arr[high] > pivot){
            high--;
        }
        if (low < high){
            swap(&arr[low], &arr[high]);
        }
    } 
    swap(&arr[0], &arr[high]);
    printf("\nPatition index: %d, element: %d\n", high, arr[high]);
    
    size1 = high;
    size2 = n - high - 1;

    p1 = (big_int*)calloc(n, sizeof(big_int));
    p2 = (big_int*)calloc(n, sizeof(big_int));

    printf("\nArray after partitioning: \n");
    display_arr(arr, n);
    printf("\nSize of the new parts: %d, %d\n", size1, size2);

    for (i = 0; i < high; i++){
        p1[i] = arr[i];
    }
    for (i = high + 1; i < n; i++){
        p2[counter++] = arr[i];
    }
    printf("\nElements in partition 1\n");
    if (size1 != 0){
        display_arr(p1, size1);
    }else{
        printf("\nNone\n");
    }
    printf("\nElements in partition 2\n");
    if(size2 != 0){
        display_arr(p2, size2);
    }else{
        printf("\nNone\n");
    }

}

big_int swap(big_int *a, big_int *b){
    big_int tmp = *a;
    *a = *b;
    *b = tmp;
}