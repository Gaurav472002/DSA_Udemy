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
        temp->prev=head;
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





int main()
{

    int arr[] = {1, 2, 4, 5, 6};

    create_linkedlist(arr, 5);
    display(head);

    // delete_linkedlist(2);
    cout << endl;

    display(head);

    return 0;
}
