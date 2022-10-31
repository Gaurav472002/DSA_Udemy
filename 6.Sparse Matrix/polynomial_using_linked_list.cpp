#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int coeff;
    int power;
    Node *next;
};
Node *poly = nullptr;

void make_polynomial()
{

    Node *temp, *last = NULL;

    int n, i;
    cout << "Enter the number of terms in the polynomial: " << endl;
    ;
    cin >> n;
    cout << "Now enter the coefficient and the power of the terms one by one:" << endl;
    for (i = 0; i < n; i++)
    {
        temp = new Node;
        
        cin >> temp->coeff >> temp->power;
        temp->next=NULL;

        if(poly==NULL){
            poly=last=temp;
        }
        else{
            last->next=temp;
            last=temp;
        }
    }
}

void display_poly(Node * ptr){
    while(ptr){
        cout<<ptr->coeff<<"x"<<ptr->power<<"+";
        ptr=ptr->next;
    }
    cout<<"\n";
}

int evalsum_poly(Node * ptr , int x){
    int  sum=0;
    while (ptr)
    {
        sum+=ptr->coeff*pow(x,ptr->power);
        ptr=ptr->next;
    }
    return sum;
    
}

void sum_poly(Node *ptr , int x){}

int main()
{

    make_polynomial();
    display_poly(poly);

    cout<< evalsum_poly(poly,1);

    return 0;
}