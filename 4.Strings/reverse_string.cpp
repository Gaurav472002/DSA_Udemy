#include <iostream>
using namespace std;

void revers_array(char arr[]){

    int i,j, temp;
    for (  j = 0; j < arr[j]; j++)
    {
        // calculating the length of the string 
    }
    j=j-1;

    for ( i = 0; i < j/2; i++,j--)
    {
            temp=arr[i];
            arr[i]=arr[j];  //swapping the values of the string
            arr[j]=temp;
    }

    // Time complexity n + n = 2n = O(n)
    
    
}

int main(){

    char name[]="Gaurav";

    cout<<name<<endl;

    revers_array(name);
    cout<<name<<endl;
    
    return 0 ;
}