#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    if(head == NULL) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }

    return node;
}

void print(Node* head) {
    if(head == NULL) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    print( head->next);
}

int listSize(Node* head) {
    int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }

    return size;
}

void printReverse2(Node* head) {
    if(head == NULL) {
        cout << endl;
        return;
    }

    printReverse2(head->next);
    cout << head->data << " ";
}

void printReverse(Node* head, int size) {
    Node* temp = head;

    if(size == 1) {
        cout << head->data << endl;
        return;
    }

    for(int i = 0; i < (size - 1); i++) {
        head = head->next;
    }

    cout << head->data << " ";
    head = temp;
    printReverse(head, size-1);
}

int main() {
    Node* node;

    node = insert(node, 1);
    node = insert(node, 2);
    node = insert(node, 3);

    print(node);
    printReverse(node, listSize(node));
    printReverse2(node);

    return 0;
}
