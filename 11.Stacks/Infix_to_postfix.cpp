#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *s;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        s = new char[size]; // creating the string dynamically
    }
    int isempty();
    int isfull();
    void push(char x);
    char pop();
    void display();
    char top_char();
    int pre(char x);
    int isOperand(char x);
};

int Stack::isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int Stack ::isfull()
{
    if (top == size - 1)
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
        s[top] = x;
    }
}

char Stack::pop()
{
    if (isempty())
    {
        return 0;
    }
    int x = s[top];
    top--;

    return x;
}

void Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << s[i] << " | " << flush;
    }
    cout << endl;
}

char Stack::top_char()
{
    if (isempty())
    {
        return -1;
    }
    return s[top];
}

int Stack::pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int Stack::isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    Stack pfx((int)len+2);
    pfx.push('^');
  
    while (infix[i] != '\0')
    {
          
        if (pfx.isOperand(infix[i]))
            pfx.s[j++] = infix[i++];
        else
        {
            if (pfx.pre(infix[i]) > pfx.pre(pfx.top))
                pfx.push(infix[i++]);
            else
            {
                pfx.s[j++] = pfx.pop();
            }
        }
    }
    while (pfx.top!=NULL)
        pfx.s[j++] = pfx.pop();
    pfx.s[j] = '\0';
    return pfx.s;
}

int main()
{

    char *infix="a+b*c";
    char *postfix= InToPost(infix);

    cout<<postfix;

    return 0;
}