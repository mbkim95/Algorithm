#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int c, q = 0, d = 0, n = 0, p = 0;
        cin >> c;
        q = c / 25;
        c -= q * 25;
        d = c / 10;
        c -= 10 * d;
        n = c / 5;
        c -= 5 * n;
        p = c;
        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }
    return 0;
}