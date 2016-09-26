//URL: https://www.hackerrank.com/challenges/balanced-brackets
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

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

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        stack<char> st;

        if( s.size()%2 != 0 || isClosePara(s[0]) ) {
            cout << "NO\n";
        } else {
            st.push(s[0]);
            bool check = true;

            for(int i = 1; i < s.size(); i++) {
                if(isClosePara(s[i])) {
                    if(!st.empty() && paraBalance(st.top(), s[i])) {
                        st.pop();
                    } else {
                        check = false;
                        break;
                    }
                } else if(isOpenPara(s[i])) {
                        st.push(s[i]);
                }
            }
    
            if(check && st.empty()) {
                cout << "YES\n";
            } else if(!check || !st.empty()) {
                cout << "NO\n";
            }
        }
    }
    
    
    return 0;
}

