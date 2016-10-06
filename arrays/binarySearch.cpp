#include <iostream>

using namespace std;

int binarySearchRecursion(int arr[], int k, int low, int high) {
    if(low > high) {
        cout << "Number is not present\n";
        return -1;
    }

    int mid = (low+high)/2;

    if(k == arr[mid]) {
        cout << "Found the guy at: " << mid << endl;
        return mid;
    } else if(k < arr[mid]) {
        binarySearchRecursion(arr, k, low, mid-1);
    } else {
        binarySearchRecursion(arr, k, mid+1, high);
    }
}

int binarySearch(int arr[], int k, int low, int high) {
    if(low > high) return -1;

    do {
        int mid = (low+high)/2;

        if(k == arr[mid]) {
            return mid;
        } else if(k < arr[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    } while(low < high);

    return -1;
}

int main() {
    int arr[6] = {12, 14, 18, 21, 25, 30};

    cout << binarySearch(arr, 3, 0, 5) << endl;

    return 0;
}
