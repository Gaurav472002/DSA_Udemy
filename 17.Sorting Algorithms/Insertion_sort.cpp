#include <iostream>
using namespace std;

void insertion_sort(int arr[],int  n){

    for ( int i = 1; i < n; i++)
    {
        int j=i-1;
        int x=arr[i];

        while (j>=0 && arr[j]>x)
        {
            arr[j+1]=arr[j]; // right shifting the elements
            j--;
        }
        arr[j+1]=x;
        
    }
    
}

void print_array(int arr[], int n){

    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(){

    int arr[]= {3,2,5,4,1};

    int n= sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr,n);
    print_array(arr,n);

    
    return 0 ;
}