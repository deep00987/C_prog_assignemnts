#include <stdio.h>
#include <stdlib.h>

void display_arr(int*, int);
void union_merge_arr(int*, int , int*, int, int*, int);


int main(){
    int *nums1, *nums2, *res, m, n, i, size;
    printf("\nEnter size of 1st sorted arr: \n");
    scanf("%d", &m);

    nums1 = (int*)malloc(sizeof(int)*m);
    printf("\nEnter elements of 1st sorted arr: \n");
    
    for (i = 0; i < m; i++){
        scanf("%d", &nums1[i]);
    }
    
    printf("\nEnter size of 2st sorted arr: \n");
    scanf("%d", &n);
    
    nums2 = (int*)malloc(sizeof(int)*n);
    size = m+n;
    res = (int*)malloc(sizeof(int)*size);
    printf("\nEnter elements of 2st sorted arr: \n");
    for (i = 0; i < n; i++){
        scanf("%d", &nums2[i]);
    }

    display_arr(nums1, m);
    display_arr(nums2, n);
    union_merge_arr(nums1, m, nums2, n, res, size);
    display_arr(res, size);

    return 0;

}

void display_arr(int* arr, int n){
    int i;
    printf("\n\n");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}

void union_merge_arr(int* nums1, int m, int* nums2, int n, int* res, int size){
    printf("\nAfter merging to arrays: \n");
    int i = 0, j = 0, k = 0;

    while (i < m && j < n){
        if (nums1[i] < nums2[j]){
            res[k++] = nums1[i++];
        }else{
            res[k++] = nums2[j++];
        }
    }

    while (i < m){
        res[k++] = nums1[i++];
    }

    while(j < n){
        res[k++] = nums2[j++];
    }
}