#include <iostream>
using namespace std;

// making ADT array
class Array
{

private:
    int *A; // this will be the pointer for my array
    int size;
    int length;

public:
    Array(int size)
    {
        this->size=size; // this is a pointer which points to the object
        //  cout<<this<<endl;
       

        A = new int[size]; // Dynamic allocation of the array in the heap
    }

    void create_array()
    {
       
        cout << "Enter the size of the array:\n";
        cin >> length;
        if (length <= size)
        {

            for (int i = 0; i < length; i++)
            {
                cout << "Enter element " << i << ":\n";
                cin >> A[i];
            }
        }
        else{
            cout<<"Enter a valid size"<<endl;
        }
    }

    void printarray()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i]<<" ";
        }
        cout<<endl;
    }

    int  binary_search(int key){  // binary search

        int low=0,high=length-1;
        

        while(low<=high){
            int mid= (low+high)/2;

            if (A[mid]==key)
            {
                return mid;
            }
            
            else if (A[mid]<key)
            {
                low= mid+1;
            }
            else{
                high=mid-1;
            }
            

        }
    return -1;
        
    }

    int Recursive_Binary_Search(int key, int low, int high){ // Should be in increasing order
        int mid=0;

        if (low<=high)
        {
            mid=(low+high)/2;

            if (key==A[mid])
            {
                return mid;
            }
            else if(key<A[mid]){
                return Recursive_Binary_Search(key,low, mid-1);
            }
            else{
                 return Recursive_Binary_Search(key, mid+1, high);
            }
            
        }
        return -1;
        
    }


};

int main()
{

    Array arr(10);
   

    arr.create_array();

    // cout<<arr.binary_search(7);

    cout<<arr.Recursive_Binary_Search(7,0,5);

   
    return 0;
}