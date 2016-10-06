#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

int partition(int arr[], int p, int q) {
    int i;
    i = p;
    int x = arr[p];

    for(int j = p; j < q; j++) {
        if(arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        } else continue;
    }
    swap(&arr[p], &arr[i]);
    return i;
}

void quickSort(int arr[], int p, int q) {
    if(p > q) {
        return;
    }

    int r = partition(arr, p, q);

    quickSort(arr, p, r-1);
    quickSort(arr, r+1, q);

    return;
}

int main() {
    int arr[] = {2, 10, 1, 5, 3, 19, 12, 9, 7, 8};

    quickSort(arr, 0, 9);

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

