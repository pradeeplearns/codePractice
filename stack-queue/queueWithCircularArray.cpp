#include <iostream>
#define MAX_SIZE 10
using namespace std;

int front = -1, rear = -1;
int arr[MAX_SIZE];

void enqueue( int data ) {
    if(front == rear) {
        cout << "Queue is Full!\n";
        return;
    }

    if(front == -1) {
        front = front + 1;
        rear = rear + 1;
        arr[rear] = data;
        return;
    }

    rear = (rear+1)%MAX_SIZE;
    arr[rear] = data;
}

void dequeue() {
    if(front == -1) {
        cout << "It's holiday!\n";
        return;
    }

    if(front == rear) {
        front = rear = -1;
        return;
    }

    front = (front + 1)%MAX_SIZE;
}

int peek() {
    if(front == -1) {
        cout << "It's holiday!\n";
        return 0;
    }

    return arr[front];
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    dequeue();
    dequeue();
    dequeue();
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);

    cout << "Top of Queue: " << peek() << endl;
    for(int i = 0; i < MAX_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
