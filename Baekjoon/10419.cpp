#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        int s = 0;
        while(s*(s+1) <= d) s++;
        cout << --s << '\n';
    }
}