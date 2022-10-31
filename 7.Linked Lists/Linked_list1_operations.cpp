#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
}*head=NULL; // declaring the  pointer for the first element of the linked list



void create_linkedlist(int arr[], int n)
{
    int i;
    head = new Node();

    Node *temp;
    Node *last;

    head->data = arr[0];
    head->next = NULL;
    last = head;

    for ( i = 1; i < n; i++)
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

// function to count number of nodes in a linked list using loops

int count_nodes(Node *ptr)
{
    int count = 0;

    while (ptr->next != 0)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// Recursive function to count the elements

int recursive_count(Node *ptr)
{
    if (ptr->next != nullptr)
    {

        return recursive_count(ptr->next) + 1;
    }
    else
    {
        return 0;
    }
}

// Recursive function to get the sum of linked list elements

int recursive_sum(Node *ptr)
{
    if (ptr->next != nullptr)
    {

        return recursive_sum(ptr->next) + ptr->data;
    }
    else
    {
        return 0;
    }
}

// Iterative function to get the max element from the linked list
int max_element(Node *ptr)
{
    int max = INT_MIN;
    while (ptr != NULL)
    {

        if (ptr->data > max)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}

// Recursive function to get the max element from the linked list
int recursive_max_element(Node *ptr)
{
    int x = 0;

    if (ptr == 0)
    {
        return INT_MIN; // if the linked list is null
    }

    x = recursive_max_element(ptr->next);
    return x > ptr->data ? x : ptr->data; // ternary operator

    // if(x>ptr->data){
    //     return x;
    // }
    // else{
    //     return ptr->data;
    // }
}

// Recursive function to get the max element from the linked list
int recursive_min_element(Node *ptr)
{
    int x = 0;

    if (ptr == 0)
    {
        return INT_MAX; // if the linked list is null
    }
    else
    {
        x = recursive_min_element(ptr->next);
        return x < ptr->data ? x : ptr->data; // ternary operator

        // if(x>ptr->data){
        //     return x;
        // }
        // else{
        //     return ptr->data;
        // }
    }
}

Node* linear_search(Node* ptr, int key){
    
    while (ptr!=NULL)
    {
        if (ptr->data==key)
        {
            return ptr;
        }
        ptr=ptr->next;
        

        
    }
    return 0;

}

Node* Improved_linear_search(Node*ptr, int key){

    Node*q;

    while (ptr!=NULL)
    {
        if(key==ptr->data){

            q->next=ptr->next;
            ptr->next=head;// moving the searched element to the first to improve the efficiency
            head=ptr;
            return ptr;

        }
        q=ptr;
        ptr=ptr->next;
    }
    return NULL;
    
}

int main()
{

    int arr[] = {141, 22, 33, 44, 1111, 1, 2};

    create_linkedlist(arr, 7);

    display(head);
    cout << endl;
    // cout<< "The count is "<< count_nodes(ptr);

    // cout << "The count is " << recursive_count(head);

    // cout << endl;
    // cout << "The sum of the linked list is " << recursive_sum(head);

    // cout << endl;
    // cout << "The max element is " << max_element(head);
    // cout << endl;
    // cout << "The max element is " << recursive_max_element(head);

    // cout << endl;
    // cout << "The minimum element is " << recursive_min_element(head);

    // cout<<linear_search(head,33)<<" ";
    cout<<Improved_linear_search(head,33)<<endl;
    display(head);
    return 0;
}