#include <iostream>
using namespace std;

int main(){
    

    char name []= "gaurav    Chakrabo rty"; // continuous spaces are called whitespaces 
    int space=0;

    for (int i = 0;name[i] ; i++)
    {
        if (name[i]==' ' && name[i-1]!=' ') //[i-1 ]conditions checks for whitespaces if the previous character is also space dont count it
        {
            space++;
        }
        
    }

    cout<<"The number of words in the string are "<< space<<endl;
    
    return 0 ;
}