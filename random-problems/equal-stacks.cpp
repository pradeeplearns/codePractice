//URL: https://www.hackerrank.com/challenges/equal-stacks
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
int result = 0;
int findMin(int a, int b, int c) {
    if(a > b) {
        a = b;
    }
    if(a > c) {
        a = c;       
    }
    
    return a;
}

int stackEquals(stack<int> st1, stack<int> st2, stack<int> st3, int sum1, int sum2, int sum3) {
    if(sum1 == sum2 && sum1 == sum3) {
        result = sum1;
        return result;
    }

    if(st1.empty() || st2.empty() || st3.empty() || sum1 <= 0 || sum2 <= 0 || sum3 <= 0) {
        result = 0;
        return result;
    }
    
    int min = findMin(sum1, sum2, sum3);    
    
    while(sum1 > min && sum1 > 0 && !st1.empty()) {
        sum1 -= st1.top();
        st1.pop();
    }
    
    while(sum2 > min && sum2 > 0 && !st2.empty()) {
        sum2 -= st2.top();
        st2.pop();
    }
    
    while(sum3 > min && sum3 > 0 && !st3.empty()) {
        sum3 -= st3.top();
        st3.pop();
    }
    
    if(!st1.empty() && !st2.empty() && !st3.empty() && sum1 > 0 && sum2 > 0 && sum3 > 0) {
        stackEquals(st1, st2, st3, sum1, sum2, sum3);
    }   
    
    return result;
}

int main(){
    clock_t tStart = clock();
    int n1;
    int n2;
    int n3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
        sum1 += h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
       sum2 += h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
       sum3 += h3[h3_i];
    }
    
    stack<int> st1, st2, st3;
    
    for(int h1_i = n1-1; h1_i >= 0; h1_i--) {
        st1.push(h1[h1_i]);
    }
    for(int h2_i = n2-1; h2_i >= 0; h2_i--) {
        st2.push(h2[h2_i]);
    }
    for(int h3_i = n3-1; h3_i >= 0; h3_i--) {
        st3.push(h3[h3_i]);
    }
    
    cout << stackEquals(st1, st2, st3, sum1, sum2, sum3) << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

