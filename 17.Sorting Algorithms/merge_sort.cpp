#include <iostream>
using namespace std;


void print_array(int *arr, int n){

    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

void merge(int *arr, int start, int end){

    int mid= (start+end)/2;

    int len1=mid-start+1;
    int len2=end-mid;

    int *left_arr= new int[len1];
    int *right_arr= new int[len2];

    int k=start;

    for (int i = 0; i < len1; i++)
    {
        left_arr[i]=arr[k++];
    }
    k=mid+1;

    for (int i = 0; i < len2; i++)
    {
        right_arr[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    int main_arr_index=start;

    while (index1<len1 && index2<len2)
    {
        if (left_arr[index1]<right_arr[index2])
        {
            arr[main_arr_index++]=left_arr[index1++];
        }
        else{
            arr[main_arr_index++]=right_arr[index2++];
        }
        
    }
    while(index1<len1){
        arr[main_arr_index++]=left_arr[index1++];
    }

    while(index2<len2){
        arr[main_arr_index++]=right_arr[index2++];
    }

    delete []left_arr;
    delete []right_arr;
    
    
    

}


void mergesort(int *arr, int start, int end){

    if (start>=end)
    {
        return ;
    }

    int mid= (start+end)/2;

    mergesort(arr, start,mid);
    mergesort(arr, mid+1,end);

    merge(arr, start , end);
    
}

int main(){

    int arr[]={5,4,1,2,4,1,1,1,3,3,99,9,3};

    int n= sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);
    print_array(arr,n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    
    
    return 0 ;
}