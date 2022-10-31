#include <iostream>

using namespace std;
 
class CircularQueue{
public:
    int size;
    int front;
    int rear;
    int* Q;

    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size];
}
 
CircularQueue::~CircularQueue() {
    delete [] Q;
}
 
bool CircularQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}
 
void CircularQueue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size; // formula for circular queue
        Q[rear] = x;
    }
}
 
int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
 
void CircularQueue::display() {
    int i = front + 1;
    do {
        cout << Q[i] <<" ";
        
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}
 
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
 
//    cq.dequeue();
//    cq.enqueue(111);
 
    cq.display();

//    cq.display();
 
    return 0;
}