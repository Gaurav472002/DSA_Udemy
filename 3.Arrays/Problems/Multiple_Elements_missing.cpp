
#include <bits/stdc++.h>

using namespace std;


void multiple_missing(int arr[], int n){ // Finding the multiple missing elements O(n^2) {Sorted array}

    int i=0;
    int diff = arr[0]-i;
    

    for ( i = 0; i < n; i++)
    {
        if (arr[i]-i !=diff)
        {
            while (diff<arr[i]-i)
            {
                cout<<"Missing Elements are:"<< i+diff <<endl;

                diff++;
            }
            

            
        }
        
    }
}

void multiple_missing_hashing(int arr[] , int n){

    // Finding the multiple missing elements O(n) {UnSorted array} using hashmap

    int max=*max_element(arr, arr + n); 

    int newarr[max]={0}; // array whose size is equal to the largest element of the primary array

    for (int i = 0; i < n; i++)
    {
        newarr[arr[i]]++;
    }

    

    for (int i = 7; i < max; i++)
    {
       if (newarr[i]== 0)
       {
         cout<<"The missing element is "<< i<<endl;
       }
      
    
       
       
        
    }
    
} 




int main(){


     int arr[]={6,7,8,9,11,12,14};
     

    int n= sizeof(arr)/sizeof(arr[0]);
    // multiple_missing_hashing(arr,n);
    multiple_missing(arr,n);

    
    
    return 0 ;
}

