#include <iostream>
using namespace std;

void shell_sort(int a[],int  n){

    for ( int gap = n/2; gap >= 1; gap=gap/2){

        for (int j = gap; j< n; j++)
        {
            for (int i = j-gap; i >= 0; i-=gap)
            {
                if (a[i+gap]>a[i])
                {
                    break;
                }
                else{
                    
                    swap(a[i+gap],a[i]);

                }
                
            }
            
        }
        
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

    int arr[]= {3,2,5,4,1,8,9,10};

    int n= sizeof(arr)/sizeof(arr[0]);

    shell_sort(arr,n);
    print_array(arr,n);

   

    
    return 0 ;
}