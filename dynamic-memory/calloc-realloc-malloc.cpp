#include <iostream>
#include <cstdlib>              //To use malloc/calloc etc this should be included

using namespace std;

int main() {
    int n;
    
    cout << "Please enter the size of array\n";
    cin >> n;

    int* A = (int*) malloc(n*sizeof(int));      //malloc assigns space of int type for n size

    for( int i = 0; i < n; i++ ) {
        A[i] = i+1;
    }

    for( int i = 0; i < n; i++ ) {
        cout << A[i] << " ";
    }

    cout << endl;

    int* B = (int*) calloc(n, sizeof(int));        //calloc needs 2 parameters size and size_t

    for( int i = 0; i < n; i++ ) {
        cout << B[i] << " ";                       //Will print 0 because calloc initiallizes with zero
    }
    cout << endl;
    
    free(B);                                        //use free to deallocate the memory block

    A = (int*) realloc(A, 2*n*sizeof(int));         //To dynamically increase the size of allocated memory
                                                    //Passing pointer to old block with new size req

    for( int i = 0; i < 2*n; i++ ) {
        cout << A[i] << " ";
    }

    free(A);

    return 0;
}

