#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} * head; // declaring the  pointer for the first element of the linked list

void create_linkedlist_circular(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;
    Node *last;

    head->data = arr[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
int count_nodes(Node *ptr)
{
    int count = 0;

    
    do{
        count++;
        ptr = ptr->next;
    }while (ptr!= head);
    
    return count;
}

int delete_circular(Node *p,int pos)
{
    
    Node *q;
    int x;

    if(pos<1 || pos> count_nodes(head) ){ // if the index is not valid
        return -1;
    }
    if (pos == 1)
    { // If you want to delete the first node

        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head==p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;

            delete head;
            head = p->next;
        }
    }

    else
    { // if you want to delete any other node
        for (int i = 1; i < pos - 1; i++)
        {
            q=p;
            p = p->next;
        }
        q = p->next;
        p->next=q->next;
        x = q->data;
        delete q;
    }
    return x;
}

void display(Node *ptr)
{

    do
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};

    create_linkedlist_circular(arr, 6);

    cout<<delete_circular(head,10);

    

 
    cout<<count_nodes(head);
    

}