#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // next pointer
    Node *prev; // previous pointer

} *head = NULL; // declaring the  pointer for the first element of the linked list and the last element

void create_linkedlist(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;
    Node *last;

    head->data = arr[0];
    head->next = head->prev = head; // if there is only one node in the linked list
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];

        temp->next = head; // last node pointing at head
        head->prev = temp; // head pointing to last node
        temp->prev = last; // making connection b/w the two nodes
        last->next = temp; // making connection b/w the two nodes

        last = temp;
    }
}
void display(Node *ptr) // will print the nodes twice if inserted from position 0
{
    do
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } while (ptr != head);
}

int count_node(Node *ptr)
{
    int count = 0;
    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr->next != head);
    return count;
}

void Insert(int pos, int x)
{ // last node = head->prev // Inserting node at first

    if (pos == 0) // if there are no elements in the linked list
    {
        head = new Node();

        Node *last;

        head->data = x;
        head->next = head->prev = head; // if there is only one node in the linked list
        last = head;
    }
    if (pos == 1)
    {
        Node *temp = new Node();
        temp->data = x;

        temp->next = head;       // pointing new node to head
        temp->prev = head->prev; // pointing new node previous to last node

        head->prev->next = temp; // pointing last node next to new node
        head->prev = temp;       // pointing previous head to new head
        head = temp;
    }
    else if (pos > count_node(head))
    { // entering  node in the last position
        Node *temp = new Node();
        temp->data = x;

        head->prev->next = temp;
        temp->prev = head->prev;
        temp->next = head;
        head->prev = temp;
    }
    else
    { // inserting node in between
        Node *p = head;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        Node *temp = new Node();
        temp->data = x;
        temp->next = p->next;
        temp->next->prev = temp;
        p->next = temp;
        temp->prev = p;
    }
}

int main()
{

    int arr[] = {1, 2, 3};

    create_linkedlist(arr, 3);

    // Insert(0,33);
    display(head);
    return 0;
}
