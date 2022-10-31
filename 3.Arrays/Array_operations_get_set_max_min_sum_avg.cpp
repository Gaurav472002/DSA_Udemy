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
            cout << "Array element: " << i << " = " ;
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

    void get_array() // function to get the value of an index of an array
    {

        int index;
        cout << "Enter the index to get the value" << endl;
        cin >> index;
        if (index >= 0 && index <= length)
        {

            cout << " The element at the postiion " << index << " is " << A[index] << endl;
        }
    }

    void set_array()// function to set a value to a particular index
    {
        int index;
        int element;
        cout << "Enter the index to set the value" << endl;
        cin >> index;
        if (index >= 0 && index <= length)
        {
            cout<<"Enter the element"<<endl;
            cin>>element;

            A[index]=element;
            
        }
    }

    void get_max(){ // function to get the max element from the array

        int max;
        max=A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i]>max)
            {
                max =A[i];
            }
            
        }
        cout<<"The max element is "<<max<<endl;
        
    }



     void get_min(){ // function to get the minimum element from the array

        int min;
        min=A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i]<min)
            {
                min =A[i];
            }
            
        }
        cout<<"The minimum element is "<<min<<endl;
        
    }

    void array_sum(){
        int sum =0;

        for (int  i = 0; i < length; i++)
        {
            sum+=A[i];
        }
        cout<<"The sum of all the elements of the array is "<< sum<<endl;
        
    }

    void array_average(){
        double average=0;
        double sum =0;

        for (int  i = 0; i < length; i++)
        {
            sum+=A[i];
        }
        average= sum/length;
        cout<<"The average of the array is "<< average<<endl;

        
    }
};

int main()
{

    Array arr(10);
    arr.create();
    arr.display();

    arr.get_array();
    arr.set_array();
    arr.get_max();
    arr.get_min();
    arr.array_sum();
    arr.array_average();

    arr.display();

    return 0;
}