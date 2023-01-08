#include <stdio.h>
#include <stdlib.h>

void get_k_max(int*, int, int);
void get_k_min(int*, int, int);
void get_median(int*, int);
int curr_max(int*, int);
void copy_arr(int*, int*, int);
void display(int*, int);

int main(){
    int *arr, *temp, n, i;
    
    printf("\nEnter the number of elements: \n");
    scanf("%d", &n);

    arr = malloc(sizeof *arr * n);
    temp = malloc(sizeof *temp * n);
    
    printf("\nEnter the array elements: \n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nElements in the arrat are: \n");
    display(arr, n);
    copy_arr(arr, temp, n);
    //display(temp, n);
    get_k_max(temp, n, 3);
    copy_arr(arr, temp, n);
    get_k_min(temp, n, 5);
    get_median(arr, n);

    return 0;
}

void get_k_max(int *arr, int n, int k){
    int max, i;

    if (k > n){
        printf("\n3rd largest element doesnt exist, array contains less elements than %d\n", k);
        return;
    }

    for (i = 0; i < k; i++){
        max = curr_max(arr, n);
    }

    printf("3rd maximum element:  %d\n", max);
}

void get_k_min(int *arr, int n, int k){
    int max, i, tmp;

    if (k > n){
        printf("\n5th minimum element doesnt exist, array contains less elements than %d\n", k);
        return;
    }
    tmp = n - k + 1;
    for (i = 0; i < tmp; i++){
        max = curr_max(arr, n);
    }

    printf("5th minimum element: %d\n", max);
}

int curr_max(int *arr, int n){
    int max, max_index = 0, i;

    for (i = 0; i < n; i++){
        if (arr[i] > arr[max_index]){
            max_index = i;
        }
    }

    max = arr[max_index];
    arr[max_index] = INT_MIN;
    return max;
}


void get_median(int *arr, int n){
    if (n < 1){
        printf("\nMedian element cannnot be found on an arr of size 0\n");
        return;
    }
    if(n % 2 == 0){
		printf("The middle element of the array is %d and %d.\n", arr[n/2-1], arr[n/2]);

	}else{
		printf("The middle element of the array is %d.\n", arr[n/2]);
	}

}

void display(int *arr, int n) {   
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copy_arr(int *arr, int *temp, int n){
    int i = 0;
    for (i = 0; i < n; i++){
        temp[i] = arr[i];
    }
}