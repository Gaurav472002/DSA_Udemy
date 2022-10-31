#include <iostream>
using namespace std;


int pascal(int n,int r){
    if(r ==0 || n==r){
        return 1;

    }
    else{
        return pascal(n-1,r-1)+pascal(n-1,r);
    }
        
    }

int main(){
    cout<<pascal(4,2);

    
    
    return 0 ;
}