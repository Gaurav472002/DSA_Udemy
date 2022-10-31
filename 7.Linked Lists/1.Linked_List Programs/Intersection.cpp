#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head ,*head2 =NULL;;

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


void create_linkedlist2(int arr[], int n)
{
    int i;
    head2 = new Node();

    Node *temp;
    Node *last;

    head2->data = arr[0];
    head2->next = NULL;
    last = head2;

    for (i = 1; i < n; i++)
    {
        temp = new Node();

        temp->data = arr[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}



Node* getIntesectionNode(Node* head1, Node* head2)
{
	while (head2) {
		Node* temp = head1;
		while (temp) {
			// if both Nodes are same
			if (temp == head2)
				return head2;
			temp = temp->next;
		}
		head2 = head2->next;
	}
	// intersection is not present between the lists
	return NULL;
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

    int arr[]={1,2,4,5,6};
    create_linkedlist(arr,5);

    int arr2[]={7,8,9,10,11};
    create_linkedlist2(arr2,5);
    head2->next=head; // linking linked list2 to 5 of linked list 1
    // display(head2);

    Node *p=getIntesectionNode(head,head2);
    cout<<p->data;

    display(head2);
   
}
   



