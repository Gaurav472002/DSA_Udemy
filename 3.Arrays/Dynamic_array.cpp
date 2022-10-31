#include <iostream>
using namespace std;

int main(){
    // changing the size of the array

    int *p=new int[5];
    int *q=new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i]=p[i]; // this will copy the values from array p to q
    }
    p=q;
    q=NULL;
    delete[]p;

    

    
    return 0 ;
}