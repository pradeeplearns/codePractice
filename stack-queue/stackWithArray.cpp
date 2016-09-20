#include <iostream>

using namespace std;
#define MAX_SIZE 101

int top = -1;
int arr[MAX_SIZE];

void push(int data) {
    if(top == 100) {
        cout << "Opps! Stack is full, Implement copy over new array if want to\n";
        return;
    }

    arr[++top] = data;
    cout << "Item " << data << " has been pushed on stack!\n";
}

void pop() {
    if(top == -1) {
        cout << "Opps! Stack is empty\n";
        return;
    }

    cout << "Item " << arr[top--] << " has been popped\n";
}

bool isEmpty() {
    if( top == -1 ) {
        return true;
    } else {
        return false;
    }
}

int stackTop() {
    return arr[top];
}

void printStack() {
    cout << "Current stack looks like this:\n";
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
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
            cout << "Top of stack is: " << stackTop() << endl;
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
