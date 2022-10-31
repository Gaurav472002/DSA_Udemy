#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int top;
    int maxSize;
    int* array;
    Stack(int max)
    {
        top=-1;
        maxSize=max;
        array=new int[max];
    }
    int isFull()
    {
        if(top==maxSize-1)
        cout<<"Will not be able to push maxSize reached"<<endl;
        return top==maxSize-1;
    }

    int isEmpty()
    {
        if(top==-1)
        cout<<"Will not be able to pop minSize reached"<<endl;
        return top==-1;
    }
    void push(int item)
    {
        if(isFull()) return;
        array[++top]=item;
        cout<<"We have pushed "<<item<<" to stack"<<endl;
    }
    int pop()
    {
        if(isEmpty()) return INT_MIN;
        return array[top--];
    }
    int peek(int pos)
    {
        if(top-pos+1<0){
            return 0;

        }
        return array[top-pos+1];
    }
};

int main()
{
    Stack stack(10);
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);
    cout<<stack.peek(4);
   
}