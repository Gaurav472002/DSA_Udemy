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
    if (ptr != nullptr)
    {
        cout << ptr->data << "->";
        display(ptr->next);
    }
}

int delete_linkedlist(int pos)
{
    Node *p = head;
    Node *q = NULL;

    int x;
    if (pos == 1)
    { // inserting a node in a first position

        x = p->data;
        head = head->next;
        delete p;
    }
    else
    {

        for (int i = 1; i <= pos - 1 && p; i++) // ptr means checking if the pointer is  not reaching null
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            x = p->data;
            q->next = p->next;
            delete p;
        }
    }
    return x;
}

int delete_last(){
    Node* p=head;
    Node* q=NULL;
    Node*last=NULL;

    while (p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    int x=p->data;
    delete p;
    q->next=NULL;
    last=q;
    return x;
}

int main()
{

    int arr[] = {1, 2, 4, 5, 6};

    create_linkedlist(arr, 5);
    display(head);

    // delete_linkedlist(2);
    cout << endl;

    delete_last();
    display(head);

    return 0;
}
