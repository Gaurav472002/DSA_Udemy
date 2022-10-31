#include <iostream>
using namespace std;

//Find the missing element from the array if the array is sorted  for n natural numbers and the last element is known


int missing_ele_sorted(int arr[], int n){
    int sum=0;

    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
    }
    int n1=arr[n-1];
    int n_sum= (n1*(n1+1))/2;


    int missing_num = n_sum-sum;

    return missing_num;
    
}


//Find the missing element from the array if the array is sorted  for n natural numbers and the last element is known

int missing_ele2(int arr[], int n){

    int i=0;
    int diff = arr[0]-i;
    int ele=0;

    for ( i = 0; i < n; i++)
    {
        if (arr[i]-i !=diff)
        {
            ele= i+diff;
            break;

            
        }
        
    }
    
    return ele;
    
    
}

void multiple_missing(int arr[], int n){ // Finding the multiple missing elements

    int i=0;
    int diff = arr[0]-i;
    int ele=0;
    int arr2[20];

    for ( i = 0; i < n; i++)
    {
        if (arr[i]-i !=diff)
        {
            while (diff<arr[i]-i)
            {
                cout<<"Elements are:"<< i+diff <<endl;

                diff++;
            }
            

            
        }
        
    }

  
    
    
    
}

int main(){

    int arr[]={6,7,8,9,11,12,14};

    int n= sizeof(arr)/sizeof(arr[0]);

    // cout<< "The missing element is "<<missing_ele_sorted(arr,n)<<endl;
    // cout<< "The missing element is "<<missing_ele2(arr,n)<<endl;

    multiple_missing(arr,n);

    
    return 0 ;
}

