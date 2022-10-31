#include <iostream>
using namespace std;

void print_array(int arr[], int n){

    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
    int count = 0;

    for (int i = low+1; i <= high; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivot_index = low + count;
    swap(arr[pivot_index],arr[low]);

    int i = low;
    int j = high;

    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i],arr[j]);
        }
        
        
    }
    return pivot_index;
}

void quick_sort(int arr[], int low, int high)
{

    if (low >= high)
    {
        return;
    }

    int partition_index = partition(arr, low, high);

    quick_sort(arr, low, partition_index - 1); // performing sort in the left subarray
    quick_sort(arr, partition_index + 1, high);  // performing sort in the right  subarray
}
int main()
{
    int arr[] = {5, 1, 7, 8, 2, 3,9,9,9,1,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr,0,n-1);
    print_array(arr,n);

    return 0;
}