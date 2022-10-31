#include <iostream>
using namespace std;

class Queue
{

public:
    int rear = -1;
    int front = -1;
    int *arr;
    int size;

    Queue(){
        arr=new int[10]; // default sized queue
    }
    Queue(int size)
    {
        arr = new int[this->size];
    }
    void enqueue(int x);
    int Dequeue();
    void Display();
};

void Queue::enqueue(int x)
{
    if (rear==size-1)
    {
        cout << "Queue overflow";
    }
    rear++;
    arr[rear] = x;
}

void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << "\n";
}

int Queue:: Dequeue()
{
    int x;
    if (front == rear)
    {
        return -1;
    }
    front++;
    x = arr[front];
    return x;
}

int main()
{
    Queue qt(5);
    qt.enqueue(1);
    qt.enqueue(2);
    qt.enqueue(3);
    qt.enqueue(4);
    qt.Dequeue();
    qt.Display();

    return 0;
}