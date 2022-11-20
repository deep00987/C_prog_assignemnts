#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll get_gcd(ll, ll);
ll get_lcm_of_n(ll*, int);
ll getLCM(ll , ll);
int main(){
    ll *nums;
    ll res = 0;
    int n;
    int i; 
    printf("\nEnter n:\n");
    scanf("\n%d\n", &n);
    nums = (ll*)malloc(n*sizeof(ll));


    for (i = 0; i < n; i++){
        // printf("\nEnter Number %d: \n", i+1);
        scanf("%lld", &nums[i]);
    }
    printf("\n\n");
    for (i = 0; i < n; i++){
        printf("%lld\t", nums[i]);
    }

    res = get_lcm_of_n(nums, n);
    if (res != -1){
        printf("\nThe LCM is: %lld\n", res);

    }else{
        printf("\nCannot be calculated (undefined).\n");
    }

    return 0;
}

ll get_lcm_of_n(ll* arr, int n){
    if (n == 1){
        return arr[0];
    }
    if (arr[0] == 0 || arr[1] == 0){
        return -1;
    }
    ll res = getLCM(arr[0], arr[1]);
    int i = 0;

    for (i = 2; i < n; i++){
        // res = res*arr[i]/get_gcd(res, arr[i]);
        if (arr[i] == 0){
            return -1;
        }
        res = getLCM(res, arr[i]);
        printf("\nSteps: %lld %lld\n", res, arr[i]);
    }
    return res;
}

ll get_gcd(ll a, ll b){
    if (b == 0){
        return a;
    }
    return get_gcd(b, a%b);
}

ll getLCM(ll a, ll b){
    return (a/get_gcd(a,b))*b;
}