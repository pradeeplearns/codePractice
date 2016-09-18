#include <iostream>

using namespace std;

void hello() {
    cout << "Hello\n";
}

void calling(void (*ptr)()) {
    ptr();
}

int main() {
    calling(hello);
    return 0;
}
