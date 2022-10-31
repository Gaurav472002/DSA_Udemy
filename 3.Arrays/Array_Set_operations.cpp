#include <iostream>
using namespace std;


void Union_array(int arr1[], int arr2[], int n1, int n2){ // This method doesn't works for duplicate values
// Elements of array 1 + elements of the array 2
    int i=0,j=0;

    while (i<n1 && j<n2)
    {
        if (arr1[i]<arr2[j])
        {
            cout<<arr1[i++]<<" ";
        }
        else if (arr2[j]< arr1[i]){

            cout<<arr2[j++]<<" ";
        }
        else{
            cout<<arr2[j++]<<" ";
            i++;
        }
        
    }

    while(i<n1){
        cout<<arr1[i++]<<" ";

    }
    while(j<n2){
        cout<<arr2[j++]<<" ";

    }
    
}

void intersection(int arr1[], int arr2[], int n1, int n2){ // Will only work for sorted order elements
// common elements between two arrays are printed
    int i=0, j=0;

    while (i<n1 && j<n2)
    {

        if (arr1[i]<arr2[j])
        {
            i++;
        }
        else if (arr2[j]< arr1[i]){

            j++;
        }
        else{
            cout<<arr2[j++]<<" ";
            i++;
        }
       
        
    }
    
}


void Difference(int arr1[], int arr2[], int n1, int n2){ 
    // Elements present  in the first array  which are not present in the second array are printed only

    int i=0, j=0;

    while (i<n1 && j<n2)
    {

        if (arr1[i]<arr2[j])
        {
            cout<<arr1[i++]<<" ";
        }
        else if (arr2[j]< arr1[i]){

            j++;
        }
        else{
            i++;
            j++;
        }
       
        
    }
    while(i<n1){
        cout<<arr1[i++]<<" ";
    }
    
}

int main(){

    int arr1[]={1,2,3,4,5,7,8,9};
    int arr2[]={2,3};

    int n1= sizeof(arr1)/sizeof(arr1[0]);
   

    int n2= sizeof(arr2)/sizeof(arr2[0]);


 

    // Union_array(arr1,arr2,n1,n2);

    // intersection(arr1,arr2,n1,n2);

    Difference(arr1,arr2,n1,n2);

    

    
    
    
    return 0 ;
}