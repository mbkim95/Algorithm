#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ptr = "*";
    int num = 1;
    cout << "int a;\nint " << ptr << "ptr = &a;\n";
    for(int i=1; i<n; i++) {
        ptr += "*";
        num++;
        string prev = num - 1 == 1 ? "" : to_string(num-1);
        cout << "int " << ptr << "ptr" << to_string(num) << " = &ptr" << prev << ";\n";
    }
    return 0;
}