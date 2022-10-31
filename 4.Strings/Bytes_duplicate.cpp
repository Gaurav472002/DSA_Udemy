#include <iostream>
using namespace std;

void duplicate_bytes(char arr[]){

    int h=0;
    int x=0;
    int i;
    for (i = 0; arr[i]!='\0'; i++)
    {
        x=1; 
        x=x<<(arr[i]-97);

        if((x & h) >0){
            cout<<"The duplicate element is "<<arr[i]<<endl;
        }
        else{
            h=h | x ;
        }
    }
    


}

int main(){

    char a[]="HELLO";

    duplicate_bytes(a);

 
    return 0 ;
}