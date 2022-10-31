#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // next pointer
    Node *prev; // previous pointer

} *head = NULL; // declaring the  pointer for the first element of the linked list

void create_linkedlist(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;
    Node *last;

    head->data = arr[0];
    head->next = NULL;
    head->prev=NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];
        temp->next = last->next;
        temp->prev=temp;
        last->next = temp;
        last = temp;
    }
}
void display(Node *ptr)
{
    if (ptr != nullptr)
    {
        cout << ptr->data << "->";
        display(ptr->next);
    }
}

void insert_dobly(int x, int pos){

    Node* temp;
    Node *p;
    
    if(pos==1){ // inserting in the first position
        temp=new Node;
        temp->data=x;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }

    else{

        p=head;
        for (int i = 1; i < pos-1; i++)
        {
            p=p->next;
        }
        temp=new Node;
        temp->data=x;
        temp->next=p->next;
        temp->prev=p;
        if(p->next!=nullptr){
            p->next->prev=temp;

        }
        p->next=temp;
        
    }
}





int main()
{

    int arr[] = {1, 2, 4, 5, 6};

    create_linkedlist(arr, 5);
    display(head);

    cout << endl;

    insert_dobly(33,3);

    display(head);

    return 0;
}
