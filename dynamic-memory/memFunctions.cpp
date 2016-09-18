#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    int* p = new int[3];
    *p = 1;
    *(p+1) = 2;
    *(p+2) = 3;

    for( int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for( int i = 0; i < n; i++ ) {
        cout << a[i] << " ";
    }

    cout << endl;

    for( int i = 0; i < 3; i++) {
        cout << *(p+i) << " ";
    }

    delete[] p;
    cout << endl;

    return 0;
}
