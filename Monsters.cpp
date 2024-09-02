#include <iostream>
using namespace std;

int main() {
    int l = 2;
    int *p = &l + 1; // Pointer arithmetic
    int *k = p - 1; // To point back to `l`
    cout << *k;     // Dereference to get the value of `l`
    return 0;
}
