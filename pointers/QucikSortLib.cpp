#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//qsort needs this particular signature compare function void* can be typecasted to any required type
int compare(const void* a, const void* b) {
    int a1 = *((int*)a);
    int b1 = *((int*)b);

    return a1-b1;
}

int main() {
    int arr[] = {-31, 22, -1, 50, -6, 4};

    qsort(arr, 6, sizeof(int), compare);

    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
