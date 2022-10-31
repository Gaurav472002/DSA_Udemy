#include <iostream>
using namespace std;

class rectangle{
    private:
    int length;
    int breadth;
    
    public:
        rectangle(){length=breadth=1;}
        rectangle(int l,int b){
            length=l;
            breadth=b;
        }
        int area(){
             return length*breadth;

        }
        int peri(){
             return 2*(length+breadth);
        };
       
        void setlength(int l){length=l;}
        int getlength(){return length;}
        
        ~rectangle(){
            cout<<"Destructor called";
        }
};



int main(){

    rectangle r(20,30);
    cout<<r.area()<<endl;
    cout<<r.peri()<<endl;
    r.setlength(10);
    cout<<r.getlength();
    
    return 0 ;
}