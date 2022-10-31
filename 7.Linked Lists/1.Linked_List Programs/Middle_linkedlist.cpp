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

int middle_node(Node*ptr){
    Node*p;
    Node*q;
    p=q=head;

    while (q!=nullptr )
    {
      
        p=p->next;
        q=q->next->next;
        
        
    }
    return p->data;
    
}

int getLen(Node *ptr){
    int count=0;
    while(ptr!=nullptr){
        count++;
        ptr=ptr->next;
    }
    return count;
}


 void printMiddle(Node *ptr)
    {
 
        if (head) {
            // find length
            int len = getLen(head);
            class Node* temp = head;
 
            // trvaers till we reached half of length
            int midIdx = len / 2;
            while (midIdx--) {
                temp = temp->next;
            }
            // temp will be storing middle element
            cout << "The middle element is [" << temp->data
                 << "]" << endl;
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

int main()
{

    int arr[]={1,2,4,5,6,7,8,9};
    create_linkedlist(arr,8);

    display(head);
    cout<<endl;

    // printMiddle(head);
    cout<<middle_node(head);
    }