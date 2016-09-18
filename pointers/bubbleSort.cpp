#include <iostream>
#include <cmath>

using namespace std;

int compareIncreasingOrder(int a, int b) {
    if(a > b) {
        return -1;
    } else {
        return 1;
    }
}

//Print in absolute value irrespective of positive negative
int compareAbs(int a, int b) {
    if(abs(a) > abs(b)) {
        return -1;
    } else {
        return 1;
    }
}

void bubbleSort( int arr[], int n, int (*compare)(int, int) ) {             //Passing compare function as argument
    int temp;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n-1; j++ ) {
            if(compare(arr[j], arr[j+1]) > 0) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted Array is.. \n";
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 2, 4, 5, 1, 6};
    
    bubbleSort(arr, 6, compareIncreasingOrder);                 //We can control compare function according to our expected output

    int arr2[] = {-1, 3, -2, 56, -100, 134};

    bubbleSort(arr2, 6, compareAbs);                            //Calling the same function with different compare function
    return 0;
}
