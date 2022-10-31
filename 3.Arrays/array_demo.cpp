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

            for (int i = 1; i <= length; i++)
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
        for (int i = 1; i <= length; i++)
        {
            cout << A[i]<<" ";
        }
        cout<<endl;
    }

    void insert_ele(){

        int ele, pos;
        cout<<"Enter the position at which you want to insert: "<<endl;
        cin>>pos;
        
        if (pos>=1 && pos<=size)
        {
            cout<<"Enter the element you want to insert:"<<endl;
            cin>>ele;
            length++;

            for (int i = length; i > pos; i--)
            {
                A[i]=A[i-1]; // right shifting the element
            }
            A[pos]=ele; // inserting the element at the desired index
            
            // length++;
            cout<<"Inserted the element "<< ele <<" at position "<< pos << " successfully"<<endl;
        }
        else{
            cout<<"Please enter a valid index"<<endl;
        }
        
    }

    void delete_ele(){

        int index;
        cout<<"Enter the index of the element  you want to delete"<<endl;
        cin>>index;
        if(index>= 1 && index<= length){
            
            int element = A[index];

            for (int i = index; i <length ; i++)
            {
                A[i]=A[i+1];
            }
            length--;
        
            cout<<"Delete the element "<< element<< " successfully"<<endl;
            
        }
        else{
            cout<<"Enter a valid Index"<<endl;
        }
    }
};

int main()
{

    Array arr(10);
   

    arr.create_array();

    arr.printarray();

    arr.insert_ele();

    arr.printarray();


    // arr.delete_ele();

    // arr.printarray();

    return 0;
}