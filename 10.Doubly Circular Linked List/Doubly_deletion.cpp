#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // next pointer
    Node *prev; // previous pointer

} *head,*last = NULL; // declaring the  pointer for the first element of the linked list and the last element

void create_linkedlist(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;

    head->data = arr[0];
    head->next = head->prev= head ; // if there is only one node in the linked list
    last = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];

        temp->next = head;  // last node pointing at head
        head->prev=temp;     // head pointing to last node
        temp->prev = last;
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
    }while(ptr != head);
}

int count_node(Node *ptr){
    int count=0;
    do
    {
        count++;
        ptr=ptr->next;
    } while (ptr!=head);
    return count;
    

}

int Delete( int pos){ 
    int x;

    if(pos<1 || pos> count_node(head)){
        return -1;
    }
    if (pos==1) // deleting the first node
    {
        Node *temp=head;
        x=temp->data;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        delete temp;
           
    }
    else if(pos==count_node(head)){ // deleting the last node
        Node *temp=last;
        last->prev->next=head;
        head->prev=last->prev;
        last=last->prev;
        delete temp;


    }
    else{
        int i=1;
        Node *temp=head;
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;

        
        
    }
   
    return 0;
  
   
    
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};

    create_linkedlist(arr, 6);
    Delete(3);
    display(head);
    

    return 0;
}
