#include <iostream>
using namespace std;

class Array
{

private:
    int *A;
    int size;

public:
    int length;
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    void create()
    {
        cout << "Enter number of elements: ";
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = ";
            cin >> A[i];
        }
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
    }

    void reverse(class Array arr, int low, int high)
    { // function to reverse the Array

        while (low <= high)
        {
            int temp = arr.A[low];
            arr.A[low] = arr.A[high];
            arr.A[high] = temp;

            low++;
            high--;
        }
    }

    void left_rotate(class Array arr)
    { // elements shifts towards left and the first element goes to right
        int x = arr.A[0];
        ;
        for (int i = 0; i < length; i++)
        {

            arr.A[i] = arr.A[i + 1];
        }
        cout << x << endl;
        arr.A[length - 1] = x; // Takes the first element to the last index
    }

    void right_rotate(class Array arr)
    { // elements shifts towards right and the last element goes to first position
        int x = arr.A[length - 1];
        ;
        for (int i = length - 1; i >= 0; i--)
        {

            arr.A[i] = arr.A[i - 1];
        }

        arr.A[0] = x; // take the last element to the first index
    }

    int check_sorted(class Array arr){

        for (int i = 0; i < length; i++)
        {
            if (arr.A[i]>arr.A[i+1])
            {
                return false;
            }
            else{
                return true;
            }
            
        }
        return 0;
        
    }

    // Write a function that shift negative values towards left and positive values towards right of an array

    void shift_left_right(class Array arr){

        int i=0;
        int j=length-1;
        while (i<j)
        {
            while (arr.A[i]<0)
            {
                i++;

            }
            while (arr.A[j]>=0)
            {
                j--;
            }
            if (i<j)
            {
               swap(arr.A[i],arr.A[j]);
            }
            
            
            
        }
        
        
    }
};

int main()
{

    Array arr(10);
    arr.create();
    arr.display();

    // arr.reverse(arr,0,4);
    // arr.left_rotate(arr);
    // arr.right_rotate(arr);
    // cout<<arr.check_sorted(arr);

    arr.shift_left_right(arr);

    arr.display();

    // arr.display();

    return 0;
}