// Normal approach using formula
#include <iostream>
using namespace std;

int naturalsum(int n){
    return n*(n+1)/2;
}

// Iterative approach

int naturalsum1(int n){
    int s=0;
    for (int i = 1; i <= n; i++)
    {
           s=s+i;
    }
    return s;
    
}

// Recursive Approach

int recur_sum(int n){
    if (n==0){
        return 0;
    }
    else{
        return recur_sum(n-1)+n;
    }
}

int main(){

    // cout<<naturalsum(10);
    // cout<<naturalsum1(10);
    cout<<recur_sum(10);
    
    return 0 ;
}