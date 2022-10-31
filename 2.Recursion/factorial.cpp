#include <iostream>
using namespace std;
// This code is contributed by Rithika palaniswamy.

// iterative approach
int factorial(int n){

    int fact=1;
    for (int  i = 2; i <= n; i++)
    {
        fact=fact*i;
    }
    return fact;
    
}

// recursive approach

int recur_fact(int n){
    if (n==0){
        return 1;

    }
    else{
        return recur_fact(n-1)*n;
    }
      

    

}

int factorialshort(int n)
{
	// single line to find factorial
	return (n == 1 || n == 0) ? 1 : n * factorialshort(n - 1);
}




int main(){

    cout<<factorial(5);
    // cout<<recur_fact(5);
    
    return 0 ;
}