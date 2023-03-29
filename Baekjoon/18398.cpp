#include <iostream>
using namespace std;

int main() {
    int t, n, a, b;
    cin >> t;
    while(t--) {
        cin >> n;
        while(n--) {
            cin >> a >> b;
            cout << a + b << ' ' << a * b << '\n';
        }
    }
    return 0;
}