#include <iostream>
using namespace std;

int main() {
    int t;
    string n;
    cin >> t;

    while(t--) {
        cin >> n;
        int m = n.length() / 2;
        if(n[m-1] == n[m]) cout << "Do-it\n";
        else cout << "Do-it-Not\n";
    }
    return 0;
}