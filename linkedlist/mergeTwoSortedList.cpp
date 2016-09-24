#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* node = new Node;

    node->data = data;
    node->next = NULL;

    return node;
}

Node* insertAtHead(Node* head, int data) {
    Node* node = newNode(data);

    if(head == NULL) {
        head = node;
        return head;
    }

    node->next = head;
    head = node;

    return head;
}

Node* insertAtTail(Node* head, int data) {
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
        cout << "List is Empty\n";
        return;
    }

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

Node* merge(Node* list1, Node* list2) {
    Node* result = NULL;
    
    if(list1 == NULL && list2 == NULL) {
        return result;
    }

    while(list1 != NULL && list2 != NULL) {
        if(list1->data < list2->data) {
            result = insertAtTail(result, list1->data);
            list1 = list1->next;
        } else {
            result = insertAtTail(result, list2->data);
            list2 = list2->next;
        }
    }

    while(list1 != NULL) {
        result = insertAtTail(result, list1->data);
        list1 = list1->next;
    }

    while(list2 != NULL) {
        result = insertAtTail(result, list2->data);
        list2 = list2->next;
    }

    return result;
}

//Be aware recursion uses extra space for recursion call in stack memory
Node* mergeRecursion(Node* list1, Node* list2) {
    Node* result;
    if(list1 == NULL) {
        return list2;
    } else if(list2 == NULL) {
        return list1;
    }
    if(list1->data < list2->data) {
        result = list1;
        result->next = mergeRecursion(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeRecursion(list1, list2->next);
    }

    return result;
}

int main() {
    Node *list1 = NULL, *list2 = NULL;
    
    list1 = insertAtHead(list1, 44);
    list1 = insertAtHead(list1, 31);
    list1 = insertAtHead(list1, 23);
    list1 = insertAtHead(list1, 11);
    list1 = insertAtTail(list1, 88);

    list2 = insertAtHead(list2, 47);
    list2 = insertAtHead(list2, 40);
    list2 = insertAtHead(list2, 22);
    list2 = insertAtHead(list2, 8);

    cout << "First List: ";
    print(list1);
    
    cout << "Second List: ";
    print(list2);

    Node* result = NULL;

    result = mergeRecursion(list1, list2);
    print(result);

    return 0;
}
