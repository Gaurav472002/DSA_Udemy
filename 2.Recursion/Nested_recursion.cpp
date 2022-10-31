#include <iostream>
using namespace std;
int fun(int n)
{
if(n>100){
   return n-10;


}
else{
       return fun(fun(n+11)); // Result will be 91 for all the values which are <= 101
}
  

}

int main(){
    cout<<fun(103);

}
