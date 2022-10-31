#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;  // pointer to left child
    Node *right; // pointer to the right child
};

Node *root = new Node();
queue<Node *> q1;

void Create()
{
    Node *p, *t;
    int x;

    cout << "Enter the value of the root node" << endl;
    cin >> x;
    root->data = x;
    root->left = root->right = nullptr;

    q1.push(root); // pushing the address of the root  node in the queue

    while (!q1.empty())
    {
        p = q1.front(); // storing the first address then popping it
        q1.pop();       // dequeue the queue

        cout << "Enter left child" << endl;
        cin >> x;
        if (x != 0)
        {
            t = new Node();
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q1.push(t);
        }

        cout << "Enter right child" << endl;
        cin >> x;
        if (x != 0)
        {
            t = new Node();
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            q1.push(t);
        }
    }
}

void preorder(Node *p)
{
    if (p) // p!=nullptr
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void Inorder(Node *p)
{
    if (p) // p!=nullptr
    {

        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

void Postorder(Node *p)
{
    if (p) // p!=nullptr
    {

        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int l = height(node->left);
        int r = height(node->right);

        /* use the larger one */
        if (l > r)
        {
            return (l + 1);
        }
        else
        {
            return (r + 1);
        }
    }
}

int count_nodes(Node *p)
{

    int x, y;

    if (p != nullptr)
    {
        x = count_nodes(p->left);
        y = count_nodes(p->right);

        return x + y + 1;
    }
    return 0;
}

int count_leaf_nodes(Node *p)
{

    int x, y;

    if (p != nullptr)
    {
        x = count_leaf_nodes(p->left);
        y = count_leaf_nodes(p->right);
        if (p->left == nullptr && p->right == nullptr)
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int count_1degree_nodes(Node *p)
{

    int x, y;

    if (p != nullptr)
    {
        x = count_1degree_nodes(p->left);
        y = count_1degree_nodes(p->right);
        if (p->left != nullptr ^ p->right != nullptr) // xor operation
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}


int count_2degree_nodes(Node *p)
{

    int x, y;

    if (p != nullptr)
    {
        x = count_2degree_nodes(p->left);
        y = count_2degree_nodes(p->right);
        if (p->left  &&  p->right ) // xor operation
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int sum_nodes(Node *p)
{

    int x, y;

    if (p != nullptr)
    {
        x = sum_nodes(p->left);
        y = sum_nodes(p->right);

        return x + y + p->data;
    }
    return 0;
}

void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void levelorder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

void level_order_queue(Node *root)
{ // shorter method using queue

    queue<Node *> q;
    cout << root->data << " ";
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->left)
        {
            cout << root->left->data << " "; // print the data of the left subtree
            q.push(root->left);
        }

        if (root->right)
        {
            cout << root->right->data << " "; // print the data of the right subtree
            q.push(root->right);
        }
    }
}

int main()
{

    Create();

    // preorder(root);
    // cout<<endl;
    // Inorder(root);
    // cout<<endl;
    // Postorder(root);
    // cout<<endl;
    // levelorder(root);
    // cout<<endl;
    // level_order_queue(root);

    cout << endl;
    cout << count_leaf_nodes(root);
    cout<<endl;
    cout << count_1degree_nodes(root);
    cout<<endl;
    cout << count_2degree_nodes(root);

    cout<<height(root);

    return 0;
}