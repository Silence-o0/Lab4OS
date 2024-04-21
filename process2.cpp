#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main() {
    int pid;
    long long int address;
    cout << "Pid: ";
    cin >> pid;
    cout << "Address: ";
    cin >> hex >> address;
    string mem_f = "/proc/" + to_string(pid) + "/mem";
    int file = open(mem_f.c_str(), O_RDONLY);
    int saved_value;
    while(1) {
        int value = 0;
        pread(file, &value, sizeof(value), address);
        if (value != saved_value) {
            cout << "Result: " << value << endl;
            sleep(10);
            saved_value = value;
        }
    }
}