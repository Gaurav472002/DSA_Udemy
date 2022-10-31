#include <iostream>
using namespace std;


void min_max(int arr[], int n){
    
    int max=arr[0],  min=arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
        }
        else{
            max=arr[i];
        }
        
    }
    cout<<"Max element is "<<  max<<endl;
    cout<<"Min element is "<<  min<<endl;
    
}
int main(){
    int arr[]={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    min_max(arr,n);
    
    return 0 ;
}