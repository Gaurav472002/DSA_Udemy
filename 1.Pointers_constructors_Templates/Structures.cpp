#include <iostream>
using namespace std;

struct rectangle{

    int length;
    int breadth;

}  r3,r4,r5;  // We can declare variables for structures here also

int main(){

    struct rectangle r1 = {2,3};

   /* r1.length = 2 ;
    r1.breadth =3; we can also set values like this */
    cout<< r1.breadth <<endl <<r1.length;

    //struct rectangle r2[54] = {{1,1},{2,2},{3,3}.......} // We can declare array of structures like this
    //cout<<r2[1].breadth // to print the value of a structure using indexing
    
    
    return 0 ;
}