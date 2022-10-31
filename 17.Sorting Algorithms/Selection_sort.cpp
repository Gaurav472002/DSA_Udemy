#include <iostream>
using namespace std;

void print_array(int arr[], int n){

    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

void selection_sort(int arr[], int n){

    for (int i = 0; i < n-1; i++)
    {

        int minimum=i;
        for (int j = i+1; j <n; j++)
        {
            if (arr[j]<arr[minimum])
            {
                minimum=j;
            }
            
        }
        swap(arr[i],arr[minimum]);
        
        
        cout<<"array after pass"<<i<<endl;
        print_array(arr,n);
        
        
    }
    
    

}

int main(){

    
    int arr[]= {5,4,3,2,1};

    int n= sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr,n);
    print_array(arr,n);
    
    return 0 ;
}