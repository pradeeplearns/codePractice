#include <iostream>
#include <stack>        //Using STL lib for stack
#include <cctype>
using namespace std;

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/') {
        return true;
    }

    return false;
}

int calculate( int a, int b, char c ) {
    if(c == '+') {
        return a+b;
    } else if( c == '-') {
        return a-b;
    } else if( c == '*' ) {
        return a*b;
    } else {
        return a/b;
    }
}

//infix = (a*b)+(c*d)-e --> postfix = ab*cd*+e-
int evalPostfix( string exp, int n ) {
    stack<int> st;
    for( int i = 0; i < n; i++ ) {
        if( exp[i] == ' ' || exp[i] == ',' ) {
            continue;
        } else if(isdigit(exp[i])) {
            int operand = 0;
            while(i < n && isdigit(exp[i])) {
                operand = (operand*10) + (exp[i] - '0');
                i++;
            }
            i--;
            st.push(operand);
        } else {
            int i2 = st.top(); st.pop();
            int i1 = st.top(); st.pop();
            
//            cout << i1 << " " << i2 << " " << calculate(i1, i2, exp[i]) << endl;
            st.push(calculate(i1, i2, exp[i]));
        }
    }

    return st.top();
}

//infix = (a*b)+(c*d)-e --> postfix = -+*ab*cde
//The Idea is to push items on stack from end of the expression
int evalPrefix( string exp, int n) {
	stack<int> st;
    for( int i = n-1; i >= 0; i-- ) {
        if( exp[i] == ' ' || exp[i] == ',' ) {
            continue;
        } else if(isdigit(exp[i])) {
            int operand = 0;
            while(i < n && isdigit(exp[i])) {
                operand = (operand*10) + (exp[i] - '0');
                i--;
            }
            i++;
            st.push(operand);
        } else {
            int i1 = st.top(); st.pop();
            int i2 = st.top(); st.pop();
            
//            cout << i1 << " " << i2 << " " << calculate(i1, i2, exp[i]) << endl;
            st.push(calculate(i1, i2, exp[i]));
        }
    }

    return st.top();
}
int main() {
    string exp;
    getline(cin, exp);

    int sz = exp.size();
    
    cout << evalPrefix(exp, sz) << endl;
    return 0;
}
