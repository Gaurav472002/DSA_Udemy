
#include <bits/stdc++.h>
using namespace std;

// Find the duplicate element from the array 

void array_dupli(int arr[], int n){

    int duplicate=0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i]== arr[i+1] && arr[i]!= duplicate)
        {
            cout<<"The duplicate element is "<< arr[i]<<endl;
        }
        duplicate=arr[i];
        
       
    }
    
    
}


// Finding duplicate elements from the array using hash map and reperesenting the count of the element also


void hash_dupli(int arr[], int n){  // Time complexity O(n)

    int max=*max_element(arr, arr + n); // finding the max element 
    cout<<max<<endl;

    int new_arr[max]={0};

    

    for (int i = 0; i < n; i++)
    {
        new_arr[arr[i]]++;
    }
    
    for (int  i = 0; i < max; i++)
    {
        if (new_arr[i]>1)
        {
            cout<<"The duplicate element is "<< i<<endl;
            cout<<"The element has occured "<< new_arr[i]<< " times"<<endl;
        }
        
    }
    
}


void count_duplicates(int arr[], int n){ // Time complexity O(n^2)

    int count =0;

    for (int  i = 0; i < n-1; i++)
    {
        count=1;
        if(arr[i]!= -1){

            for (int j = i+1; j < n; j++)
            {
                if(arr[i]==arr[j]){
                    count++;
                    arr[j]=-1;

                    
                }
            }
            if(count>1){
                cout<<"The duplicate element is "<< arr[i]<< " occuring "<< count<< " times"<<endl;
            }
            
        }
    }
    
}
int main(){

    int arr[]={20,1,100,2,3,55,6,6,6,55};

    int n= sizeof(arr)/sizeof(arr[0]);

    // array_dupli(arr,n);

    // hash_dupli( arr,  n);
    count_duplicates(arr,n);
    
    return 0 ;
}