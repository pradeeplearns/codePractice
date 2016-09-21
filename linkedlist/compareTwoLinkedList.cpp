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

Node* insert(Node* head, int data) {
    Node* node = newNode(data);

    if(head == NULL) {
        head = node;
        return head;
    }

    node->next = head;
    head = node;

    return head;
}

bool sizeCompare(Node* list1, Node* list2) {
    if( list1 == NULL && list2 == NULL) {
        return true;
    } else if( (list1 == NULL && list2 != NULL) || (list1 != NULL && list2 == NULL)) {
        return false;
    } else {
        int count1 = 0, count2 = 0;
        Node* temp1 = list1;
        Node* temp2 = list2;

        while(temp1 != NULL) {
            count1++;
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            count2++;
            temp2 = temp2->next;
        }

        if(count1 == count2) {
            return true;
        } else {
            return false;
        }
    }
}

void print(Node* head) {
    if(head == NULL) {
        cout << "List is empty\n";
    } else {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Node *list1 = NULL, *list2 = NULL;

    list1 = insert(list1, 1);
    list1 = insert(list1, 1);
    list1 = insert(list1, 1);
    list1 = insert(list1, 1);
    list1 = insert(list1, 3);
    
    list2 = insert(list2, 1);
    list2 = insert(list2, 1);
    list2 = insert(list2, 1);
    list2 = insert(list2, 1);
    list2 = insert(list2, 3);

    if(sizeCompare(list1, list2)) {
        while(list1 != NULL && list1->data == list2->data) {
            list1 = list1->next;
            list2 = list2->next;
        }

        if(list1 != NULL || list2 != NULL) {
            cout << "List are not same\n";
        } else {
            cout << "Lists are same\n";
        }
    } else {
        cout << "Lists are not same\n";
    }

    return 0;
}
