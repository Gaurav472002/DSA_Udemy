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


void insertion_circular(int x, int pos)
{
    Node *temp;
    Node *p;

    if(pos==0){ 
        temp=new Node;
        temp->data=x;
    }

    if(head==NULL){// if  the linked list is empty
        head=temp;
        head->next=head;
    }
    else if( pos==1){ // insertion at position 1
        p=head;

        while(p->next!= head)
        {
            p=p->next;
        }
        temp=new Node;
        temp->data=x;
        p->next=temp;
        temp->next=head;
        head=temp;
    }
    else{
        p=head;

        for (int  i = 1; i <= pos-1; i++)
        {
            p=p->next;
        }
        temp=new Node;
        temp->data=x;
       
        temp->next=p->next;
        p->next=temp;
        


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


int main()
{

    int arr[]={1,2,3,4,5,6};

    // create_linkedlist_circular(arr,6);
    // display(head);

   insertion_circular(22,0);
   cout<<endl;
   display(head);
}