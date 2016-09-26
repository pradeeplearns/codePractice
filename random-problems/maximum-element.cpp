//URL https://www.hackerrank.com/challenges/maximum-element
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    
    stack<int> st, mx;
    mx.push(0);
    
    while(t--) {
        int type;
        
        cin >> type;
        
        if(type == 1) {            
            int x;
            cin >> x;

            st.push(x);
            if(st.top() >= mx.top()) {      //Max or equal both stand for a push
                mx.push(x);
            }
        } else if(type == 2) { 
            if(st.top() == mx.top()) {
                mx.pop();
                st.pop();
            } else {
                st.pop();
            }                
        } else {
            cout << mx.top() << endl;
        }
    }
    
    return 0;
}

