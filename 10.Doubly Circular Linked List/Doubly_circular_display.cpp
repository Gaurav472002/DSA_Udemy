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
    head->next = head->prev= head ; // if there is only one node in the linked list
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];

        temp->next = head;  // last node pointing at head
        head->prev=temp;     // head pointing to last node
        temp->prev = last->prev;
        last->next = temp;
      

        last = temp;
    }
}
void display(Node *ptr)
{
    do 
    {
        cout << ptr->data << "->";
        ptr=ptr->next;
    }while(ptr->next != head->next);
}

int main()
{

    int arr[] = {1, 2, 4, 5, 6};

    create_linkedlist(arr, 5);

    display(head);





 
    

    return 0;
}
