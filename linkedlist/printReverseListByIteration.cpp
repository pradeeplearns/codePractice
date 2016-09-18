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
        cout << "List is empty!\n";
    } else {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }

        cout << endl;
    }
}

int listSize(Node* head) {
    int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }

    return size;
}

void printReverse(Node* head) {
    if(head == NULL) {
        cout << "List is Empty\n";
    } else {
        Node* temp = head;
        int size = listSize(head);
        
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < (size - i - 1); j++) {
                head = head->next;
            }
            cout << head->data << " ";
            head = temp;
        }
    }
}

int main() {
    Node* node;

    node = insert(node, 1);
    node = insert(node, 2);
    node = insert(node, 3);

    print(node);
    printReverse(node);

    return 0;
}
