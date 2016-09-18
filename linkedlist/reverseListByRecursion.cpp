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

    return head;
}

void print(Node* head) {
    if(head == NULL) {
        cout << "Sorry the list is empty!\n";
    } else {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }

        cout << endl;
    }
}

Node* reverseList(Node* head) {
    if(head == NULL) return NULL;

    if(head->next == NULL) {
        return head;
    }

    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    Node* node;

    node  = insert(node, 1);
    node = insert(node, 2);
    node = insert(node, 3);

    print(node);

    node = reverseList(node);

    print(node);
    return 0;
}
