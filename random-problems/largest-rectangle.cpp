//URL: https://www.hackerrank.com/challenges/largest-rectangle  Maximum Histogram Area Problem.
//Tut: https://www.youtube.com/watch?v=ZmnqCZp9bBs
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    int arr[n];
    int area = 0, max_area = -1;
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];        
    }
    int i;
    for(i = 0; i < n;) {
        if(st.empty() || arr[st.top()] <= arr[i]) {
            st.push(i++);
        } else {
            int top = st.top();
            st.pop();
            
            if(st.empty()) {
                area = arr[top]*i;
            } else {
                area = arr[top]*(i - st.top() - 1);
            }
            
            if(area > max_area) {
                max_area = area;
            }
        }
    }
    
    while(!st.empty()) {
        int top = st.top();
        st.pop();

        if(st.empty()) {
            area = arr[top]*i;
        } else {
            area = arr[top]*(i - st.top() - 1);
        }
            
        if(area > max_area) {
            max_area = area;
        }        
    }
    
    cout << max_area << endl;
    
    return 0;
}

