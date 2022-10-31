// Taylor Series:  e^x = 1+ x/1  + x^2/2! + x^3/3! 

#include <iostream>
using namespace std;


double taylor(int x, int n){
    static double p=1,  f=1;

    double r;
    if (n==0)
    {
        return 1;
    }
    else{
        r=taylor(x,n-1);
        p=p*x;
        f=f*n;


        return  r + p/f;
    }
    
}

// more efficient approach this will reducee the number of multiplications and reduce the complexity

double taylor_Horner(double x, double n){
    static double s=1;

    if (n==0)
    {
        return s;
    }
    s=1+x/n*s;
    return taylor_Horner(x, n-1);

  
    
}

//iterative approach

double e_taylor(int x, int n){
    double s=1;
    int i;
    double num=1;
    double den=1;
    for ( i = 1; i <= n; i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
    
}

int main(){
    cout<<taylor(3,10)<<endl; // increase the value of n for more precision
    cout<<taylor_Horner(3,10)<<endl;
    cout<<e_taylor(3,10);
    return 0 ;
}