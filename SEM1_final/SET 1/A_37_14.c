#include <stdio.h>

typedef long long int ll;

ll binomialCoeff(int, int);
ll fact(int);

int main(){
    int n, i, j, k; 
    ll ele;
    printf("\nEnter the number of rows to be printed:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        //print spaces
        for(j = n - i; j > 0; j--){
            printf(" ");
        }
        // print i elements for ith line
        for (k = 0; k <= i; k++)
        {   
            //choose from line i, k i.e ncr(i, k)
            ele = binomialCoeff(i , k);
            printf("%3lld", ele); 
            
        }
        printf("\n");
    }


    return 0;
}


ll fact(int n)
{
    if (n == 0){
        return 1;
    }
    return n*fact(n - 1);
}

ll binomialCoeff(int n, int k)
{
    return fact(n) / (fact(n - k) * fact(k));
}