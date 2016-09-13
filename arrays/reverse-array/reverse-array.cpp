#include <iostream>
#include <cstdlib>

using namespace std;

void reverse(int arr[], int left, int right) {
    while(left < right) {
        swap(arr[left++], arr[right--]);
    }
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int length;
    cin >> length;

    int arr[length];
    
    for(int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    int divider;
    cin >> divider;

    if(length < divider) {
        reverse(arr, 0, length-1);
    } else {
        for(int i = 0; i < length; i=i+divider) {
            if(i+divider < length) {
                reverse(arr, i, i+divider-1);
            } else {
                reverse(arr, i, length-1);
                break;
            }
        }
    }

    for( int i = 0; i < length; i++ ) {
        cout << arr[i] << " ";
    }

    return 0;
}
