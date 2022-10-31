#include <iostream>
using namespace std;

int fun2(int n){
    
    if(n>0){
        

        return fun2(n-1)+n;
    }
    return 0;
}


//  int x=0; // global variable

int fun(int n){
    static int x=0; // static variable 
    // both static and global variables will give the same result

   

    if(n>0){
        x++;

        return fun(n-1)+x;
    }
    return 0;
}




int main(){

    cout<<fun(5)<<endl;
    cout<<fun(5);
    
    return 0 ;
}