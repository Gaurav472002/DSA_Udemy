#include <iostream>
using namespace std;

class diagonal_matrix{
    private:
    int n;
    int*A;

    public:

        diagonal_matrix(int n){
            this->n=n;
            A=new int[n]; // Dynamic allocation 
        }

        void setdata(int i, int j, int x);

        int getdata(int i, int j);

        void display();

        ~diagonal_matrix(){ // Destructor
            delete[]A;
            cout<<"Memory Freed ";
        }



};

void diagonal_matrix::setdata(int i, int j,int x){

    if (i==j)
    {
        A[i-1]=x;
    }
    
    
}


int diagonal_matrix::getdata(int i, int j){
    if(i==j){
        return A[i-1];
    }
    else{
        return 0;
    }
}

void diagonal_matrix::display(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                cout<<A[i]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<"\n";
        
    }
    
}
int main(){

    diagonal_matrix d1(5);
    d1.setdata(1,1,5);
    d1.setdata(2,2,6);
    d1.setdata(3,3,7);
    d1.setdata(4,4,8);
    d1.setdata(5,5,9);

    // cout<<d1.getdata(5,5)<<endl;
    d1.display();
    return 0 ;
}