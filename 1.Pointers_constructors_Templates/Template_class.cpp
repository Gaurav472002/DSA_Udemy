#include <iostream>
using namespace std;

template<class T>
class arithmetic{

    private:
        T a;
        T b;

    public:
        arithmetic(T a, T b);
        T add();
        T sub();

};
template<class T>
arithmetic<T>::arithmetic(T a, T b){
    this->a=a;
    this->b=b;
}
template<class T>
T arithmetic<T>::add(){ // using the scope resolution operator for the fucntion definiton
    T c;
    c=a+b;
    return c;
}
template<class T>
T arithmetic<T>::sub(){
    T c;
    c=a-b;
    return c;
}

int main(){

    // arithmetic<int> ar(10,5);
    // cout<<ar.add()<<endl;
    // cout<<ar.sub()<<endl;


    arithmetic<float> ar(10.5,5.6);
    cout<<ar.add()<<endl;
    cout<<ar.sub()<<endl;

    // Using th class templates we can use same class for different data types whether its int , float or char easily.
    
    return 0 ;
}