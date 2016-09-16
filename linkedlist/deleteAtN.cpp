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

Node* deleteAtN(Node* head, int position) {
    Node* current;

    if(head == NULL) {
        cout << "List is Empty, Nothing to delete\n";
    } else if(position == 0) {
        current = head->next;
        delete head;
        head = current;
    } else {
        Node* temp = head;

        while(position > 1) {
            head = head->next;
            position--;
        }

        current = head->next->next;
        delete head->next;
        head->next = current;

        head = temp;
    }

    return head;
}

void printList(Node* node) {
    if(node == NULL) {
        cout << "List is Empty\n";
    } else {
        while(node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
}

int main() {
    Node* node;

    node = insert(node, 1);
    node = insert(node, 2);
    node = insert(node, 3);

    printList(node);
    node = deleteAtN(node, 1);
    printList(node);
    return 0;
}
