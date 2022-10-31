#include <iostream>
#include<stack>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left_child;
    Node *right_child;
};

class BST
{

public:
    Node *root; // pointer to the root node
    BST()
    {
        root = nullptr;
    }
    Node *getroot() // function to get the root node
    {
        return root;
    };
    void insert(int key);
    void Inorder(Node *node);
    Node *search(int key);

    Node *recursive_insert(Node *node, int key);
    int height(Node *p);

    Node *Pre(Node *p);
    Node *Suc(Node *p);

    Node *delete_node(Node *p, int value);
    
    int Check_BST(Node *p);
    void createFromPreorder(int pre[], int n);

    Node *bstfrompreorder(vector <int>& A);

    Node *build(vector <int>& A, int& i, int bound);


};

Node *BST::search(int key)
{
    Node *t = root;
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->left_child;
        }
        else
        {
            t = t->right_child;
        }
    }
    return nullptr; // if the required key is not found in the key
}

void BST::insert(int key)
{ // function to insert a node in the BST iteratively
    Node *t = root;
    Node *p, *r;

    if (root == nullptr) // if there are no nodes in the BST
    {
        p = new Node();
        p->data = key;
        p->left_child = p->right_child = nullptr;
        root = p;
        return;
    }
    while (t != nullptr) // Searching for the appropriate position to enter the node 
    {
        r = t; // this will store the root of the last subtree
        if (key < t->data)
        {
            t = t->left_child; // keep moving left until we reach the end
        }
        else if (key > t->data)
        {
            t = t->right_child; // keep moving right until we reach the end
        }
        else
        {
            return; // if the key already exists in the tree
        }
    }

    p = new Node();
    p->data = key;
    p->left_child = p->right_child = nullptr;

    if (key < r->data) // check if the value is smaller than the root
    {
        r->left_child = p;
    }
    else
    {
        r->right_child = p;
    }
}

Node *BST::recursive_insert(Node *current, int key) // function to insert node recursively
{
    if (current == nullptr)
    {

        Node *t = new Node();
        t->data = key;
        t->left_child = t->right_child = nullptr;
        return t; // return address of the newly
    }
    else if (key < current->data)
    {
        current->left_child = recursive_insert(current->left_child, key); // this will return the address of the newly created left node and then 
        // this node will be connected with the current node
    }
    else
    {
        current->right_child = recursive_insert(current->right_child, key);
    }
    return current; // returning the root node
}

void BST::Inorder(Node *node) // function for inorder traversal
{
    if (node != nullptr)
    {
        Inorder(node->left_child);
        cout << node->data << " ";
        Inorder(node->right_child);
    }
}

int BST::height(Node *p)
{ // function to calculate the height of the tree
    if (p == nullptr)
    {
        return 0;
    }
    int x = height(p->left_child);
    int y = height(p->right_child);

    return x > y ? x + 1 : y + 1;
}

Node *BST::Pre(Node *p)
{
    while (p && p->right_child != nullptr)
    {
        p = p->right_child;
    }
    return p;
}

Node *BST::Suc(Node *p)
{
    while (p && p->left_child != nullptr)
    {
        p = p->left_child;
    }
    return p;
}

Node *BST::delete_node(Node *p, int value) // function to delete a node from the bst
{
    Node *q;
    if (p == nullptr)
    {
        return nullptr;
    }
    if (p->left_child == nullptr && p->right_child == nullptr)
    { // if there is only one node present in the BST
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if (value < p->data)
    {
        p->left_child = delete_node(p->left_child, value);
    }
    else if (value > p->data)
    {
        p->right_child = delete_node(p->right_child, value);
    }

    else // check whether we have to replace the deleted value with predecessor or successor
    {
        if(height(p->left_child)> height(p->right_child)){  // if left subtree is longer delete from it
            q=Pre(p->left_child);
            p->data=q->data;
            p->left_child=delete_node(p->left_child,q->data);
        }
        else{
            q=Suc(p->right_child); // if right subtree is longer delete from it
            p->data=q->data;
            p->right_child=delete_node(p->right_child,q->data);

        }
    }
    return p;
}

int BST:: Check_BST(Node *p){ // function to check whether a tree is BST or Not

    static Node *prev=nullptr;

    if (p!=nullptr)
    {
        if (!Check_BST(p->left_child))
        {
            return 0;
        }
        if (prev!=nullptr && p->data<= prev->data) // if the previous node is not null and the root value is less than child
        {
            return 0;
        }
        prev=p;
        return Check_BST(p->right_child);
        
    }
    else{
        return 1;
    }
    
}

void BST::createFromPreorder(int *pre, int n) {
 
    // Create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->left_child = nullptr;
    root->right_child = nullptr;
 
    // Iterative steps
    Node* t;
    Node* p = root;
    stack<Node*> stk;
 
    while (i < n){
        // Left child case
        if (pre[i] < p->data){
            t = new Node;
            t->data = pre[i++];
            t->left_child = nullptr;
            t->right_child = nullptr;
            p->left_child = t;
            stk.push(p);
            p = t;
        } else {
            // Right child cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new Node;
                t->data = pre[i++];
                t->left_child = nullptr;
                t->right_child = nullptr;
                p->right_child = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

Node * BST::bstfrompreorder(vector<int>& A){

            int i=0;
            return build(A, i, INT_MAX); // INT_MAX is the uppper bound
}

Node *BST::build(vector<int>& A , int& i, int bound){
    if(i==A.size() || A[i]>bound){ // if iterator goes out of limit
        return nullptr;
    }
    Node *root=new Node();
    root->data=A[i++]; // creating the first root node

    root->left_child=build(A,i,root->data);
    root->right_child=build(A,i,bound);
    return root;

}


int main()
{

    BST t1;

    // t1.insert(1); // 

    t1.root = nullptr;

    t1.root=t1.recursive_insert(t1.root,5);
    t1.recursive_insert(t1.root, 3);
    t1.recursive_insert(t1.root, 6);


    // t1.root = t1.recursive_insert(t1.getroot(), 2);
    // t1.root = t1.recursive_insert(t1.getroot(), 3);

    // t1.delete_node(t1.getroot(),22);
    t1.Inorder(t1.getroot()); // inorder traversal should return the sorted list
    
    // cout<<endl;
    // cout<<t1.Check_BST(t1.getroot());


    // BST b;
    // vector<int> vect{8,5,1,7,10,12};

    // b.Inorder(b.bstfrompreorder(vect));
    return 0;
}