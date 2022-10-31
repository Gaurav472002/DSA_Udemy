#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head ; // declaring the  pointer for the first element of the linked list

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




void display(Node *ptr)
{

   do
   {
    cout<<ptr->data<<"->";
    ptr=ptr->next;
   } while (ptr!=head);
   
}

void circular_recursive_display(Node *ptr){

    static int flag=0;

    if(ptr!=head ||  flag ==0){
        flag=1;

        cout<<ptr->data<<"->";
        circular_recursive_display(ptr->next);
    }
    flag=0;
}
int main()
{

    int arr[]={1,2,3,4,5,6};

    create_linkedlist_circular(arr,6);
    // display(head);
    circular_recursive_display(head);

   
}