#include <iostream>
using namespace std;

int main(){
    // 2D array using pointers

    int* A[3]; // Array of 3 pointers

    //Array A[3][4]
    A[0]= new int[4];
    A[1]= new int[4];
    A[2]= new int[4];



    // 2D array using pointers

    int**B;
    B= new int*[3];

    B[0]= new int[4];
    B[1]= new int[4];
    B[2]= new int[4];

    // B[2][3]=33;
    

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           cout<< B[i][j]<<" ";
        }
        
    }
    
  
    return 0 ;
}