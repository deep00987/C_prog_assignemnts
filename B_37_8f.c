#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double find_cos(double, int, double);

int main(){

    double x, res = 1; 
    int n;
    
    printf("\nEnter sin value: \n");
    scanf("%lf", &x);

    printf("\nEnter nth term: \n");
    scanf("%d", &n);


    res = find_cos(x, n, res);
    printf("\nResult of cos(%lf): %lf \n", x, res);
   
    return 0;
}

double find_cos(double x, int n, double res){
    if(n > 0){
        res = 1 - ((x * x * res)/(n * (n - 1)));
        return find_cos(x, n - 2, res);
    }else{
        return res;
    }

}