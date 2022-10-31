#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev; // previous pointer
    int data;
    Node *next; // next pointer

} *head = NULL; // declaring the  pointer for the first element of the linked list

void create_linkedlist(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;
    Node *last;

    head->data = arr[0];
    head->next = head->prev=NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];
        temp->next = last->next;
        temp->prev=last;
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

void reverse_doubly(Node *ptr){
    Node *temp;
    while (ptr!=NULL)
    {
        temp=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=temp;

        ptr=ptr->prev;

        if( ptr!=NULL && ptr->next ==NULL){
            head=ptr;
        }
    }
    
}





int main()
{

    int arr[] = {1, 2, 4, 5, 6};

    create_linkedlist(arr, 5);
    display(head);

    reverse_doubly(head);
    cout << endl;

    display(head);

    return 0;
}
