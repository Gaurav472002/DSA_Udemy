#include <iostream>
using namespace std;
 
class Array{
 
private:
    int* A;
    int size;
    int length;
 
public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }
 
    void create(){
        cout << "Enter number of elements: " ;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }
 
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
 
    
    int linear_search(){
        int key;
        cout<<"Enter the element you want to search"<<endl;
        cin>>key;
        int result;

        for (int i = 0; i < length; i++)
        {
            if (A[i]==key)
            {
                return i;
            }
            
            
        }
        return -1;
       
    
                
            
    
        

    }
};

int main() {
 
 
    Array arr(10);
    arr.create();
    arr.display();
    int a=arr.linear_search();
    if (a==-1)
    {
            cout<<"Element not found";
    }
    else{
        cout<<a<<endl;
    }
    
 
 
    return 0;
}