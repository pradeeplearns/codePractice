#include <iostream>

using namespace std;

int top = -1;
char arr[101];

void push(char c) {
    arr[++top] = c;
}

char pop() {
    return arr[top--];
}

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        push(s[i]);
    }
    
//    char* ch = new char[10];

    for(int i = 0; i < s.size(); i++) {
        s[i] = pop();
    }

    cout << s << endl;
    return 0;
}
