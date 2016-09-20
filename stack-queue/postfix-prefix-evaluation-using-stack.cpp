#include <iostream>
#include <stack>        //Using STL lib for stack

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
    stack<char> st;
    for( int i = 0; i < n; i++ ) {
        if(!isOperator(exp[i])) {
            st.push(exp[i]);
        } else {
            int i2 = st.top() - '0'; st.pop();
            int i1 = st.top() - '0'; st.pop();
            
            cout << i1 << " " << i2 << " " << calculate(i1, i2, exp[i]) << endl;
            st.push(calculate(i1, i2, exp[i]));
        }
    }

    return st.top();
}
                    
int main() {
    string exp;
    cin >> exp;

    int sz = exp.size();
    
    cout << evalPostfix(exp, sz) << endl;
    return 0;
}
