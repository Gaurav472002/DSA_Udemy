#include <iostream>
using namespace std;


void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int maximum(int arr[], int n){

    int max= INT_MIN;

    for (int  i = 0; i < n; i++)
    {
        if (arr[i]> max)
        {
            max =arr[i];
        }
        
    }
    return max;
}

void count_sort(int arr[], int n){

    int max = maximum(arr, n);

    int *c = new int[max+1]; // creating a new array whose size is equal to the maximum element of the array



    for (int i = 0; i < max+1; i++)
    {
        c[i]=0; // initialising the new array with 0's
    }

    for (int i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }
    

    int i=0;
    int j=0;

    while (j<max+1)
    {
        if (c[j]>0)
        {
            arr[i++]=j; 
            c[j]--; // reducing the count from the dynamic array
        }
        else{
            j++;
        }
    }

    delete[] c; // deleting the dynamic array from the heap memeory
    
    
    
}
int main(){

    int arr[]={5,1,3,200,400000000,5,6,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    count_sort(arr,n);

    // cout<<maximum(arr,n);

    print_array(arr,n);
    
    return 0 ;
}