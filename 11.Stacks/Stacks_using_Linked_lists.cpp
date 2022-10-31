#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    
};Node *top=nullptr; // maintaining the top pointer to track the top element of the stack

int isempty(Node *top)
{
    if (top==nullptr)
    {
        return 1;
    }
    return 0;
    
}

int isfull()
{
    Node *ptr = new Node;
    if (ptr==nullptr)
    {
        return 1;
    }
    return 0;
    
}

void push(int x)
{
    Node *p = new Node;

    if (isfull())
    {
        cout << "Stack overflow";
    }
    else
    {
        p->data = x;
        p->next=top;
        top=p;
    }
}

int pop(){
    if (isempty(top))
    {
        return 0;
    }
    Node *t=top;
    int x=t->data;
    top=top->next;
    delete t;
    return x;
    
}

int peek(int pos){
    int i;

    Node *p=top;
    for ( i = 0;  p!=nullptr && i < pos-1; i++)
    {
        p=p->next;
    }
    if (p!=nullptr)
    {
        return p->data;
    }
    return -1;
    
}

int stack_top(){
    if(top){
        return top->data;
    }
    return -1;
}
int main()
{
    // push(3);
    // pop();
    push(3);
    cout<<isempty(top);
    cout<<stack_top();

    return 0;
}