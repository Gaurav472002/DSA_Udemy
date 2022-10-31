#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head = NULL; // declaring the  pointer for the first element of the linked list

void create_linkedlist(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;
    Node *last;

    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

void display(Node *ptr)
{

    if (ptr != NULL)
    {
        cout << ptr->data << "->";
        display(ptr->next);
    }
}


int  checksorted(){

    int x= INT_MIN;
    Node* p=head;
    int result;

    while (p!=NULL)
    {
        if(p->data<x){
            
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
    
   
    
    
}


int main(){

    int arr[]={1,2,374,5,6};

    create_linkedlist(arr,5);
    display(head);
    cout<<endl;
    cout<<checksorted();
    
    return 0 ;
}