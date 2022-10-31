#include <iostream>
using namespace std;

// this is for max heap considering index starts from 0
void Heap_insertion(int arr[], int n){ //  n is the index of the newly inserted element

    int i=n;
    int temp=arr[n];

    // here considering the index of the heap starts from 0
    while(i>0 && temp>arr[i %2==0? (i/2)-1 : i/2]){// if the index is even return i/2 -1 the parent node else the parent is i/2
        
        arr[i]=arr[i % 2==0? (i/2)-1 : i/2];
        i=i % 2==0? (i/2)-1 : i/2;
    }
    arr[i]=temp;
}

void Insert(int A[], int n) // index starts from 1
{
    int i = n;
    int temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

// this is the min  heap
void Heap_insertion_min_heap(int arr[], int n){ //  n is the index of the newly inserted element

    int i=n;
    int temp=arr[n];

    while(i>0 && temp<arr[i %2==0? (i/2)-1 : i/2]){// if the index is even return i/2 -1 the parent node else the parent is i/2
        
        arr[i]=arr[i % 2==0? (i/2)-1 : i/2];
        i=i % 2==0? (i/2)-1 : i/2;
    }
    arr[i]=temp;
}

void print_max_heap(int arr[], int n){


    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}


void Create_heap(int arr[], int n){ // function to create heap from a given array
    for (int i = 0; i < n; i++)
    {
        Heap_insertion(arr,i);
    }
    
}
int main(){

    int arr[]={ 14, 15, 5, 20, 30, 8, 40}  ;

    
   Create_heap(arr,7);

   print_max_heap(arr,7);




    return 0 ;
}