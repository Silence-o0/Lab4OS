#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    int x;
    cout << "My pid: " << ::getpid() << '\n';
    cout << "Value address: " << &x << endl;
    while (1) {
        cout << "Enter num: ";
        cin >> x;
    }
}