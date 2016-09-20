#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    return node;
}

void push(int data) {
    Node* node = newNode(data);

    if( top == NULL ) {
        top = node;
        return;
    }

    node->next = top;
    top = node;
}

Node* pop() {
    if( top == NULL) {
        return NULL;
    }

    Node* temp = top;
    top = temp->next;

    return top;
}

Node* insert(Node* head, int data) {
    Node* node = newNode(data);

    if(head == NULL) {
        head = node;
        return head;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
    
    return head;
}

void print(Node* head) {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return;
}

int main() {
    Node* list = NULL;

    list = insert(list, 1);
    list = insert(list, 2);
    list = insert(list, 3);
    list = insert(list, 4);
    list = insert(list, 5);
    list = insert(list, 6);

    print(list);

    Node* temp = list;
    while(temp != NULL) {
        push(temp->data);
        temp = temp->next;
    }

    print(top);
  
    temp = top; list = top;

    while(temp != NULL) {
        //temp = insert(temp, top->data);
        temp->next = pop();
        temp = temp->next;
    }

    print(list);
    return 0;
}
