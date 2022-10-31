#include <iostream>
using namespace std;


struct rectangle{
        int length;
        int breadth;
        

    };

int main(){
    struct rectangle *p; // Declaring the pointer

    p=new rectangle;
    // (*p).breadth=33;
    // (*p).length=43;  Instead of this we can use arrow -> operator

    p->breadth=33;
    p->length=43;

    cout<<p->breadth<<endl;
    cout<<p->length<<endl;
    

    
    return 0 ;
}