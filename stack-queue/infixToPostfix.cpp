#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

bool isOperator( char c ) {
    if( c == '+' || c == '-' || c == '*' || c == '/' ) {
        return true;
    }

    return false;
}

bool isOperatorBigger( char c1, char c2 ) {

    map<char, int> opertor;// = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    opertor['+'] = 1;
    opertor['-'] = 1;
    opertor['*'] = 2;
    opertor['/'] = 2;
    
    if( opertor.find(c1)->second >= opertor.find(c2)->second ) {
        return true;
    }

    return false;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string result;

    for( int i = 0; i < exp.size(); i++ ) {
        if(!isOperator(exp[i]) || exp[i] == ' ' || exp[i] == ',') {
            result.append(1, exp[i]);
        } else if(st.empty() || (!st.empty() && !isOperatorBigger(st.top(), exp[i]))) {
            st.push(exp[i]);
        } else {
            if(!st.empty() && isOperatorBigger(st.top(), exp[i])) {
                while(!st.empty()) {
                    result.append(1, st.top());
                    st.pop();
                }
                st.push(exp[i]);               
            }
        }
    }

    while(!st.empty()) {
        result.append(1, st.top());
        st.pop();
    }

    return result;
}

string infixToPostfixWithParanthesis(string exp) {
    stack<char> st;
    string result;

    for( int i = 0; i < exp.size(); i++ ) {
        if(!isOperator(exp[i]) || exp[i] == ' ' || exp[i] == ',' ) {
            if(exp[i] == '(' || exp[i] == ')') continue;
            result.append(1, exp[i]);
        } else if(st.empty() || (!st.empty() && !isOperatorBigger(st.top(), exp[i])) || exp[i] == '(') {
            st.push(exp[i]);
        } else {
            if(!st.empty() && ((isOperatorBigger(st.top(), exp[i]) || exp[i] == ')'))) {
                while(!st.empty() && st.top() != ')') {
                    result.append(1, st.top());
                    st.pop();
                }
                if(!st.empty()) st.pop();       //Pop one open paranthesis if exist
                st.push(exp[i]);               
            }
        }
    }

    while(!st.empty()) {
        if(st.top() == '(' || st.top() == ')') {
            st.pop();
            continue;
        }
        result.append(1, st.top());
        st.pop();
    }

    return result;
}

int main() {
    string s = "2*3+5*4-9";
    string input;
    getline(cin, input);
    cout << "Infix " << s << " == Postfix: " << infixToPostfix(s) << endl;
    cout << "Output Postfix is: " << infixToPostfixWithParanthesis(input) << endl;

    return 0;
}

