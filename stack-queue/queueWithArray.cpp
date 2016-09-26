#include <iostream>

using namespace std;

int front = -1, rear = -1;
int arr[10];

void enqueue(int data) {
    if(front == -1) {
        front = front + 1;
        rear = rear + 1;
        arr[rear] = data;
        return;
    }

    rear = rear + 1;
    arr[rear] = data;
}

void dequeue() {
    if(front == rear) {
        front = rear = -1;
        return;
    }

    front = front + 1;
}

int peek() {
    if(front == -1) {
        cout << "Empty queue\n";
        return 0;
    }

    return arr[front];
}

bool isEmpty() {
    if(front == rear && front == -1) {
        return true;
    }

    return false;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    enqueue(4);

    cout << "Top of Queue: " << peek() << endl;
    cout << "Front: " << front << " Rear: " << rear << endl;

    for(int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


