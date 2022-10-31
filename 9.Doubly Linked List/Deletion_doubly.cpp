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
    head->prev = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

int count_nodes(Node *ptr)
{
    int count = 1;

    while (ptr->next != nullptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
void display(Node *ptr)
{
    if (ptr != nullptr)
    {
        cout << ptr->data << "-> ";
        display(ptr->next);
    }
}

int delete_circular(Node *p ,int pos)
{

    

    int x;
    int i=1;

    if (pos < 1 || pos > count_nodes(head))
    {
        return -1;
    }

    if (pos == 1)
    {
        head = head->next;
        if (head)
        {
            head->prev = NULL; // pointing second  pointer to null after deleting the first node
        }
        x = p->data;
        delete p;
    }

    else
    {
        while(i < pos)
        {
            p = p->next;
            i++;
        }

        p->prev->next = p->next;

        if (p->next != nullptr){
             p->next->prev = p->prev;

        } // if the node is not the last node

       

        x = p->data;
        delete p;
    }
    return x;
}

int main()
{

    int arr[] = {1, 2, 7, 4, 5};

    create_linkedlist(arr, 5);
    // display(head);

    delete_circular(head,4);
    cout << endl;

    display(head);

    return 0;
}
