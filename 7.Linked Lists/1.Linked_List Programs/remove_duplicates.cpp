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

void remove_duplicates()
{
    Node *p = head;
    Node *q = head->next;

    while (q != nullptr)
    {

        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{

    int arr[] = {1, 2, 3, 3, 4, 5};

    create_linkedlist(arr, 5);

    display(head);
    remove_duplicates();
    cout << endl;
    display(head);

    return 0;
}