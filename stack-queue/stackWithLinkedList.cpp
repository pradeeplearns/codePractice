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

    if(top == NULL) {
        top = node;
    } else {
        node->next = top;
        top = node;
    }
}

void pop() {
    if(top == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;

    cout << temp->data << " has been popped\n";
    top = temp->next;
    delete temp;
}

void stackTop() {
    cout << "Top of stack: " << top->data << endl;
}

bool isEmpty() {
    if(top == NULL) {
        return true;
    } else {
        return false;
    }
}
    
void printStack() {
    if(top == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int exit = 1;
    while(exit != 0) {
        cout << "Chose options from below:\nChose A for push\nChose B for pop\nChose C for top\nChose P for printing stack\nChose E for Exit\n";

        char c;
        cin >> c;

    	switch(c) {
        	case 'A': 
        	    cout << "Please enter the number you want to push on stack\n";
        	    int temp;
        	    cin >> temp;
        	    push(temp);
        	    break;
        	case 'B':
        	    pop();
        	    break;
        	case 'C':
        	    stackTop();
        	    break;
        	case 'P':
        	    printStack();
        	    break;
        	default:
        	    exit = 0;
        	    cout << "Thank you!\n";
        	    break;
    	}
    }

    return 0;
}
