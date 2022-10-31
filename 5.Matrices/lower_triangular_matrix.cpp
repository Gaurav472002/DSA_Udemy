#include <iostream>
using namespace std;

class Lower_triangular_matrix{
    private:
    int n;
    int*A;

    public:

        Lower_triangular_matrix(int n){
            this->n=n;
            A=new int[n]; // Dynamic allocation 
        }

        void setRowMajor(int i, int j, int x);

        int getdata(int i, int j);

        void display();

        void get_details(int n){

            cout<<"The number of non zero elements are "<< n*(n+1)/2<<endl;
            cout<<"The number of  zero elements are "<< n*((n-1)/2)<<endl;
        }

        ~Lower_triangular_matrix(){ // Destructor
            delete[]A;
            cout<<"Memory Freed ";
        }



};

void Lower_triangular_matrix::setRowMajor(int i, int j,int x){

    if (i>=j)
    {
        A[i*(i-1)/2+j-1]=x; // row major formula
    }
    
    
}


int Lower_triangular_matrix::getdata(int i, int j){
    if(i>=j){
        return A[i*(i-1)/2+j-1];
    }
    else{
        return 0;
    }
}

void Lower_triangular_matrix::display(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i>=j)
            {
                cout<<A[i*(i-1)/2+j-1]<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<"\n";
        
    }
    
}
int main(){

    Lower_triangular_matrix rm(5);


    rm.setRowMajor(1, 1, 1);
    rm.setRowMajor(2, 1, 2);
    rm.setRowMajor(2, 2, 3);
    rm.setRowMajor(3, 1, 4);
    rm.setRowMajor(3, 2, 5);
    rm.setRowMajor(3, 3, 6);
    rm.setRowMajor(4, 1, 7);
    rm.setRowMajor(4, 2, 8);
    rm.setRowMajor(4, 3, 9);
    rm.setRowMajor(4, 4, 9);
    rm.setRowMajor(5, 1, 9);
    rm.setRowMajor(5, 2, 9);
    rm.setRowMajor(5, 3, 9);
    rm.setRowMajor(5, 4, 9);
    rm.setRowMajor(5, 5, 9);
    rm.display();

    rm.get_details(5);

    
    return 0 ;
}