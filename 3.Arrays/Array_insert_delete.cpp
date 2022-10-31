#include <iostream>
using namespace std;

class Array
{

private:
    int *A;
    int size;

    int index;
    int element;

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
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }

    void insert()
    {
        cout << "Enter the position at which you want to insert" << endl;
        cin >> index;
        if (index >= 0 && index <= length)
        {
            cout << "Enter the element you want to insert" << endl;
            cin >> element;

            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = element;
            length++;
            cout << "Element inserted Successfully" << endl;
        }
        else{
            cout<<"please enter a valid index"<<endl;
        }

    }

    void delete1()
    {

        cout << "Enter the index of the element You want to delete" << endl;
        cin >> index;
        if (index>=0 && index< length)
        {
           

            int x= A[index];

            for (int i = index; i < length; i++)
            {
                A[i] = A[i +1];
            }
         
            length--;
            cout << "Deleted element"<< x << "Successfully" << endl;
        }
        else
        {

           cout<<"please enter a valid index"<<endl ;
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
};

int main()
{

    Array arr(10);
    arr.create();
    // cout<<arr.length<<endl;

    arr.display();
    arr.insert();
    arr.display();

    return 0;
}