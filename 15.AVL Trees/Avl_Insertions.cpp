#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    int height;
    Node *lchild; // pointer to the left child
    Node *rchild; // pointer to the right child
};

class Avl
{

public:
    Node *root;
    Avl()
    { // constructor to instantitate the AVL tree
        root = nullptr;
    }

    Node *get_root()
    { // function to get the root of the Avl Tree
        return root;
    }

    int NodeHeight(Node *p);    // function to get the height of the tree
    int Balancefactor(Node *p); // Function to calculate the Balance factor for a tree

    void Inorder_traversal(Node *p); // function for Inorder traversal of the tree
    void Inorder_traversal(){
        Inorder_traversal(root);
    }; 
    Node *LL_Rotation(Node *p);
    Node *RR_Rotation(Node *p);
    Node *LR_Rotation(Node *p);
    Node *RL_Rotation(Node *p);

    Node *r_insert(Node *p, int key); // function to insert nodes in the Avl trees
};

int Avl::NodeHeight(Node *p)
{
    int hl; // height of left subtree
    int hr; // heighbt of right subtree

    hl = (p != nullptr && p->lchild != nullptr) ? p->lchild->height : 0;
    hr = (p != nullptr && p->rchild != nullptr) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1; // return right or left subtree whose height is greater
}

int Avl::Balancefactor(Node *p)
{

    int hl; // height of left subtree
    int hr; // heighbt of right subtree

    hl = (p != nullptr && p->lchild != nullptr) ? p->lchild->height : 0;
    hr = (p != nullptr && p->rchild != nullptr) ? p->rchild->height : 0;

    return hl - hr; // Balance factor = Height of left subtree - Height of Right subtree
}

void Avl::Inorder_traversal(Node *p)
{

    if (p != nullptr)
    {
        Inorder_traversal(p->lchild);
        cout << p->data << " ";
        Inorder_traversal(p->rchild);
    }
}

Node *Avl::LL_Rotation(Node *p)
{

    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
    {
        root = pl; // if the current node was the root node change it to the new node after rotation
    }
    return pl; // Returning the new root node after LL rotation
}

Node *Avl::RR_Rotation(Node *p)
{

    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    // modifying the tree perfroming rotation
    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
    {
        root = pr; // if the current node was the root node change it to the new node after rotation
    }
    return pr; // Returning the new root node after RR rotation
}

Node * Avl::LR_Rotation(Node *p){ // Function for LR Rotation

    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    // creating links for the child of plr
    pl->rchild=plr->lchild; 
    p->lchild=plr->rchild;
   
    plr->lchild=pl;
    plr->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    if (root==p)
    {
        root=plr;
    }
    cout<<"Lr was done"<<endl;
    return plr;

}

Node * Avl::RL_Rotation(Node *p){ // Function for RL Rotation

    Node *pr= p->rchild;
    Node *prl= pr->lchild;

    // creating links for the child of plr
    pr->lchild=prl->rchild; 
    p->rchild=prl->lchild;
   
    prl->rchild=pr;
    prl->lchild=p;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    if (root==p)
    {
        root=prl;
    }
    return prl;

}

Node *Avl::r_insert(Node *p, int key)
{
    Node *t;
    if (p == nullptr)
    {

        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data)
    {
        p->lchild = r_insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = r_insert(p->rchild, key);
    }

    p->height = NodeHeight(p);

    if (Balancefactor(p) == 2 && Balancefactor(p->lchild) == 1) // positive BF means tree heavy on the left side
    {
        return LL_Rotation(p);
    }
    else if (Balancefactor(p) == -2 && Balancefactor(p->rchild) == -1){ // Negative BF means tree heavy on the right side
        return RR_Rotation(p);
    }
    else if (Balancefactor(p) == 2 && Balancefactor(p->lchild) == -1){ // 
        return LR_Rotation(p);
    }
    else if (Balancefactor(p) == -2 && Balancefactor(p->rchild) == 1){ // Negative BF means tree heavy on the right side
        return RL_Rotation(p);
    }

    return p; // returning the root node
}
int main()
{

    Avl tree;

    tree.root=tree.r_insert(tree.root,20);
    tree.root=tree.r_insert(tree.root,10);
    tree.root=tree.r_insert(tree.root,11);

    // tree.Inorder_traversal();

    cout<<tree.root->data;
    cout<<tree.root->lchild->data;
    cout<<tree.root->rchild->data;


    return 0;
}