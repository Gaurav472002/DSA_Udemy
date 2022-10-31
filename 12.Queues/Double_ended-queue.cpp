#include <iostream>
using namespace std;
#define SIZE 10
class dequeue
{
    int a[10], front, rear;

public:
    dequeue();
    void insert_at_beg(int);
    void insert_at_end(int);
    void delete_fr_front();
    void delete_fr_rear();
    void show();
};
dequeue::dequeue()
{
    front = -1;
    rear = -1;
}
void dequeue::insert_at_end(int i)
{
    if (rear >= SIZE - 1)
    {
        cout << "\n insertion is not possible, overflow!!!!";
    }
    else
    {
        if (front == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear = rear + 1;
        }
        a[rear] = i;
        cout << "\nInserted item is" << a[rear];
    }
}
void dequeue::insert_at_beg(int i)
{
    if (front == -1)
    {
        front = 0;
        a[++rear] = i;
        cout << "\n inserted element is:" << i;
    }
    else if (front != 0)
    {
        a[--front] = i;
        cout << "\n inserted element is:" << i;
    }
    else
    {
        cout << "\n insertion is not possible, overflow!!!";
    }
}
void dequeue::delete_fr_front()
{
    if (front == -1)
    {
        cout << "deletion is not possible::dequeue is empty";
        return;
    }
    else
    {
        cout << "the deleted element is:" << a[front];
        if (front == rear)
        {
            front = rear = -1;
            return;
        }
        else
            front = front + 1;
    }
}
void dequeue::delete_fr_rear()
{
    if (front == -1)
    {
        cout << "deletion is not possible::dequeue is empty";
        return;
    }
    else
    {
        cout << "the deleted element is:" << a[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            rear = rear - 1;
    }
}
void dequeue::show()
{
    if (front == -1)
    {
        cout << "Dequeue is empty";
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    dequeue d;

    d.insert_at_beg(5);
    d.insert_at_end(1);
    d.insert_at_end(2);
    d.insert_at_end(3);
    d.insert_at_end(4);
    cout << endl;
    d.show();
}
