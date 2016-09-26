#include <iostream>
#include <stack>

using namespace std;

/*
   Any closed paranthesis should be balanced by latest open parathesis, anytime this condition fails then string is not balanced
   Suggested input (([{}]))
*/

bool isOpenPara(char c) {
    if(c == '(' || c == '[' || c == '{') {
        return true;
    }
    return false;
}

bool isClosePara(char c) {
    if(c == ')' || c == ']' || c == '}') {
        return true;
    }
    return false;
}

bool paraBalance(char c1, char c2) {
    if( (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}')) {
        return true;
    }

    return false;
}

int main() {
    string s;

    cin >> s;

    stack<char> st;

    if( s.size()%2 != 0 || isClosePara(s[0]) ) {
        cout << "Paranthesis are not ballanced\n";
        return 0;
    }

    st.push(s[0]);
	bool check = true;
    for(int i = 1; i < s.size(); i++) {
        if(isClosePara(s[i])) {
            if(!st.empty() && paraBalance(st.top(), s[i])) {
                st.pop();
            } else {
				check = false;
                cout << "Paranthesis are not ballanced\n";
                return 0;
            }
        } else if(isOpenPara(s[i])) {
                st.push(s[i]);
        }
    }

	if(check && st.empty()) {
		cout << "Paranthesis are ballanced\n";
	} else if(!check || !st.empty()) {
		cout << "Paranthesis are not ballanced\n";
	}  

    return 0;
}          
