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

void insert_linkedlist(int pos, int x)
{
    Node *ptr;
    Node *temp;

    if (pos == 0)
    { // inserting a node in a first position

        temp = new Node;
        temp->data = x;
        temp->next = head;
        head = temp;
    }
    else if (pos > 0)
    { // Insertion in middle

        ptr = head;

        for (int i = 0; i < pos - 1 && ptr; i++) // ptr means checking if the pointer is  not reaching null
        {
            ptr = ptr->next;
        }
        if (ptr)
        {
            temp = new Node;
            temp->data = x;
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
}

void Insert_last(Node *ptr,int x)
{

    Node *temp = new Node;
    Node *last; // This pointer will keep track of the last node

    temp->data = x;
    temp->next = NULL;

    if (ptr == NULL) // if the linked list is empty
    {
        head = last = temp;
    }
    else
    {

        last->next = temp;
        last = temp;
    }
}

void sorted_insertion(Node *p, int x)
{
    Node *temp ;
    Node *q = NULL;

    temp=new Node;
  
    temp->data = x;
    if (head == NULL)
    {
        head = temp;
    }
    while (p!=NULL && p->data < x)
    {
        q = p;
        p = p->next;
    }
    if (p == head)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = q->next;
        q->next = temp;
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

int main()
{

    int arr[]={1,2,4,5,6};
    create_linkedlist(arr,5);

    // sorted_insertion(head,1);
    // sorted_insertion(head,8);
    display(head);
    cout<<endl;
    Insert_last(head,3);
    display(head);
}