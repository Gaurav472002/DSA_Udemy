#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *s;
    
    Stack(int size){
        this->size=size;
        top=-1;
        s =new char[size]; // creating the string dynamically
    }
    int isempty();
    int isfull();
    void push(char x);
    char pop();
    void display();
    char top_char();
};

int Stack::isempty()
{
    if (top==-1)
    {
        return 1;
    }
    return 0;
    
}

int Stack ::isfull()
{
    if (top==size-1)
    {
        return 1;
    }
    return 0;
    
}

void Stack::push(char x)
{
    if (isfull())
    {
        cout << "Stack overflow";
    }
    else
    {
       top++;
       s[top]=x;

       
    }
}

char Stack:: pop(){
    if (isempty())
    {
        return 0;
    }
    int x =s[top];
    top--;

    return x;
    
}


void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << s[i] << " | " << flush;
    }
    cout << endl;
}
 
char Stack::top_char() {
    if (isempty()){
        return -1;
    }
    return s[top];
}

bool parenthesis_match(char *exp){

    Stack st((int)strlen(exp));

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i]=='(')
        {
            st.push(exp[i]);
        }
        else if(exp[i]==')'){
            if (st.isempty())
            {
                return false; 
            }
            st.pop();
            
        }
        
    }
    return st.isempty() ? true : false; // prints true if the stack is empty means the parenthesis are totally balanced
    
    
}
 



int main()
{

    // char exp[]="((a+b)*(c-d))";
    char exp[]="((a+b)*(c-d)";
    cout<<parenthesis_match(exp);


    return 0;
}