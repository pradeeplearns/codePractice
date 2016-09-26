#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;              //We will maintain a tail pointer to the list to ensure enqueue/dequeue in O(1) time

Node* newNode(int data) {
    Node* node = new Node;
    
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue(int data) {
    Node* temp = newNode(data);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = tail->next;
}

void dequeue() {
    if(head == NULL) return;

    if(head == tail) {
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

int peek() {
    if(head == NULL) return 0;

    return head->data;
}

bool isEmpty() {
    if(head == NULL) return true;

    return false;
}

void print() {
    if(isEmpty()) cout << "No data\n";

    Node* temp = head;

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    dequeue();
    enqueue(7);
    enqueue(8);
    enqueue(9);
    dequeue();
    print();


    return 0;
}
