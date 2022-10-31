//Loops exists in a linked list when the last node rather than pointing at Null points at another Node

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

int checkloop (Node *ptr){
    Node *p;
    Node *q;

    p=q=ptr;

    do{
        p=p->next;
        q=q->next;

        q=q!=NULL?q->next:q;
    }while(p && q && p!=q);

    return p==q?1:0;

}

void display(Node *ptr)
{

    if (ptr != NULL)
    {
        cout << ptr->data << "->";
        display(ptr->next);
    }
}


int main(){
    int arr[]={1,2,3,4,5};
    create_linkedlist(arr,5);

    // Node*t1,*t2;
    // t1=head->next->next;
    // t2=head->next->next->next;
    // t2->next=t1;

    cout<<checkloop(head);

}