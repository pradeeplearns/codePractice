#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtN(Node *head, int data, int position) {
    Node *node = new Node;
    node->data = data;
    node->next = NULL;

    if(head == NULL) {
        head = node;
    } else {
        if(position == 0) {
            node->next = head;
            head = node;
        } else {
            Node *temp = head;      //Saving current head of linkedlist

            while(position > 1) {   //Checking with 1 because linked list is starting from 0 index 
                head = head->next;
                position--;
            }

            node->next = head->next;
            head->next = node;

            head = temp;
        }
    }

    return head;
}

void printList(Node *head) {
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

int main() {
    Node *node;

    node = insertAtN(node, 2, 0);
    node = insertAtN(node, 3, 0);
    node = insertAtN(node, 4, 1);
    
    printList(node);

    return 0;
}
