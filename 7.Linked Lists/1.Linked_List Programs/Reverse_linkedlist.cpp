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

void reverse_linkedlist(){
    Node* p=head;
    int arr[5]={};

    int i=0;
    while (p!=NULL)
    {
        arr[i]=p->data; // copying element from linked list to array
        p=p->next;
        i++;
    }
    p=head;
    i--; // shifting the iterator to the last element of the array
    while (p!=NULL)
    {
        p->data=arr[i--]; // copying element from array to linked list in reverse order
        p=p->next;
    }
}


void sliding_pointer_reverse(){
 // This method is more favorable rather than shifting elements to reverse the list
    Node *p =head;
    Node *q=nullptr;
    Node *r=nullptr;

    while(p!=nullptr){
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    head=q; // making the last  node as the first node as the linked list is reversed
}

void recursive_reverse(Node *q , Node *p){
        if(p!=nullptr)
        {
            recursive_reverse(p,p->next); //q=p and p=p->next
            p->next=q;
        }
        else{
            head=q;
        }
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5};

    create_linkedlist(arr, 4);

    display(head);
    cout << endl;

    // reverse_linkedlist();

    // sliding_pointer_reverse();
    Node *q=NULL;
    recursive_reverse(q,head);
    display(head);

    return 0;
}