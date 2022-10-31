#include <iostream>
using namespace std;


void fun1(int n){   // THis will give 3 2 1 as output
    if(n>0){
        cout<<n<<endl;
        fun1(n-1); //recursive call
    }
}


void fun2(int n){   // THis will give 1 2 3  as output
    if(n>0){
        
        fun2(n-1); //recursive call
        cout<<n<<endl;
    }
}
int main(){

    int x=3;
    // fun1(x);
    fun2(x);
    
    return 0 ;
}


/*  for Fun1 the recursive tree will be
        fun1(3)
        /    \
       /      \
      3        fun1(2)
               /      \
              /        \
             2        fun1(1)
                      /      \
                     /        \
                     1       fun1(0)  */  // so the output will be 321



                     /*  for Fun2 the recursive tree will be
                            fun2(3)
                            /    \
                           /      \
                        fun2(2)    3      
                        /      \
                       /        \
                    fun2(1)      2
                      /      \
                     /        \
                    fun2(0)    1    when fun2(0) will get terminated it
                     will  go back to fun2(1) print 1 and then fun2(2)and print 2 
                     and  then fun2(3) an print 3*/