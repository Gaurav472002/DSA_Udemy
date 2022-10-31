#include <iostream>
using namespace std;

// Parameter passing call by value
void swap_value(int x, int y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}


// Parameter passing call by address
void swap_address(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

// Parameter passing call by Reference
void swap_reference(int &x, int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int main(){

    int num1= 30, num2=40;
    cout<<"Before Swap: "<<num1<<endl<<num2<<endl;
    // swap_reference(num1,num2);
   
    // swap_address(&num1, &num2);
    swap_value(num1,num2); // this will not swap the values
    cout<<"After Swap: "<<num1<<endl<<num2<<endl;


    
    return 0 ;
}