#ifndef FUNCTIONSEXAMPLE_H
#define FUNCTIONSEXAMPLE_H

class Node{
    public:
    int data;
    Node *next;

}*head=nullptr;

void create_linkedlist(int arr[], int n);

void display(Node* ptr);

#endif