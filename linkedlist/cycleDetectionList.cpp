#include <iostream>
#include <list>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* hasCycle(Node* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* first = head;
    Node* second = head->next->next;
    
    while(first != NULL && second != NULL) {
        if(first == second) {
            return first;
        } else {
            first = first->next;
            second = second->next->next;
        }
    }

    return NULL;
}

Node* removeCycle(Node* head) {
    
    Node* first = hasCycle(head);
    Node* temp = head;
    Node* loop;

    while(1) {
        loop = first;
        while(loop->next != first && loop->next != temp)
            loop = loop->next;

        if(loop->next == temp) {
            break;
        }

        temp = temp->next;
    }

    loop->next = NULL;

    return head;
}

Node* newNode(int data) {
    Node* node = new Node;

    node->data = data;
    node->next = NULL;

    return node;
}

Node* insert( Node* head, int data ) {
    Node* node = newNode(data);

    if(head == NULL) {
        head = node;
        return head;
    }

    node->next = head;
    head = node;

    return head;
}

Node* makeCycle(Node* head, int pos) {
    Node* temp = head;
    Node* cyc = head;

    while(pos != 0) {
       cyc = cyc->next;
       pos--;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = cyc;

    return head;
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

int main() {
    Node* head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = makeCycle(head, 2);

    if(hasCycle(head) != NULL) {
        cout << "Has cycle\n";
    }
    
    head = removeCycle(head);
    print(head);

    return 0;
}

