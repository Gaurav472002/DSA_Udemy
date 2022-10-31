//Loops exists in a linked list when the last node rather than pointing at Null points at another Node

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head = NULL, *secondhead=NULL, *thirdhead =NULL ;// declaring 3 head pointers

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
    secondhead = new Node();

    Node *temp;
    Node *last;

    secondhead->data = arr[0];
    secondhead->next = NULL;
    last = secondhead;

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

void merge_linked_list(Node *p , Node *q){

    Node *last;

    if(p->data < q->data){
        thirdhead=last=p;
        p=p->next;
        thirdhead->next=nullptr; // First element of list 1 inserted in list  3
    }
    else{
        thirdhead=last=q;
        q=q->next;
        thirdhead->next=nullptr; // First element of list 2 inserted in list  3

    }

    while (p && q)
    {
        if(p->data< q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;

        }
    }
    if(p!=NULL){
        last->next=p; // if second list is completed refer to the remaining elements of list 1
    }
    if(q!=NULL){
        last->next=q; // if second list is completed refer to the remaining elements of list 1
    }
    
}


int main(){
    int arr[]={10,20,30,40,70,80,90};

    int arr2[]={5,12,33,55};
    create_linkedlist(arr,7);
    create_linkedlist2(arr2,4);
    
    
    merge_linked_list(head,secondhead);

    display(thirdhead);

    

    

}