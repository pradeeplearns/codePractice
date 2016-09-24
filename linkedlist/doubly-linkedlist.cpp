#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void print(Node* head) {
    if(head == NULL) cout << "This list is empty\n";

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void reversePrint(Node* head) {
    if(head == NULL) cout << "This list is empty\n";

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

//Insert a new node at the head of list
Node* insertAtHead(Node* head, int data) {
    Node *node = newNode(data);

    if(head == NULL) {
        head = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }

    return head;
}

//Insert at the tail of list
Node* insertAtTail(Node* head, int data) {
    Node* node = newNode(data);

    if(head == NULL) {
        head = node;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = node;
        node->prev = temp;
    }

    return head;
}

//Insert at a given position list start index 1
Node* insertAtN(Node* head, int data, int pos) {
    Node* node = newNode(data);

    if(head == NULL) {
        head = node;
    } else {
        Node* temp = head;

        while(pos > 1) {
            temp = temp->next;
            pos--;
        }
        
        node->next = temp;
        node->prev = temp->prev;
        temp->prev->next = node;
        temp->prev = node;
    }

    return head;
}

//Delete at head
Node* deleteAtHead(Node* head) {
    if(head == NULL) {
        cout << "List is empty.. what to delete\n";
        return NULL;
    }

    if(head->next == NULL) {
        delete head;
        cout << "It was Only one node list so deleted it!\n";
        return NULL;
    }

    Node* temp = head;

    temp->next->prev = NULL;
    head = temp->next;
    delete temp;

    return head;
}
    
//Delete at tail
Node* deleteAtTail(Node* head) {
    if(head == NULL) {
        cout << "List is empty.. what to delete\n";
        return NULL;                            
    }

    if(head->next == NULL) {
        delete head;
        cout << "It was Only one node list so deleted it!\n";
        return NULL;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;

    return head;
}

//Delete at given pos List starting index 0
Node* deleteAtN(Node* head, int pos) {
    if(pos == 1) {
        return deleteAtHead(head);
    }

    Node* temp = head;

    while(pos > 1) {
        pos--;
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;
    delete temp;

    return head;
}

Node* reverseList(Node* head) {
    Node* temp = head;
    Node* swap = NULL;

    while(temp != NULL) {
        swap = temp->prev;
        temp->prev = temp->next;
        temp->next = swap;

        temp = temp->prev;                  //Prev Because address has changed with swap
    }

    if(swap != NULL) head = swap->prev;     //Checking in case of single node

    return head;
}

int main() {
    Node* head = NULL;

    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtN(head, 5, 2);
    print(head);
    reversePrint(head);
    head = reverseList(head);    
    cout << "List has been reversed permanently\n";
    print(head);
    head = deleteAtHead(head);

    print(head);

    head = deleteAtTail(head);
    head = deleteAtN(head, 3);

    print(head);
    reversePrint(head);
    
    return 0;
}


