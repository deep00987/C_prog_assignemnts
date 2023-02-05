#include <stdio.h>

int main()
{
    int n;
    int i,j;
    int left_sum, right_sum, flag = 0;

    printf("\nEnter the number of rooms: ");
    scanf("%d", &n);
    i = 1;
    int total = n*(n+1)/2;

    for(i=1; i<=n; i++)
    {
        int num = i-1;
        
        left_sum = num*(num+1)/2;
        right_sum = total - left_sum - i;
       

        if(left_sum == right_sum){
            printf("\n%d\n ", i);
            flag = 1;
        }
        
    }
    if (!flag){
        printf("The room is not found ;;;");
    }
    return 0;
}