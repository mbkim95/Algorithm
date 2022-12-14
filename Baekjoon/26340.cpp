#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int w = a, h = b, f = c;

        while (f--) {
            if (w > h) w /= 2;
            else h /= 2;
        }
        cout << "Data set: " << a << ' ' << b << ' ' << c << '\n';
        cout << max(w, h) << ' ' << min(w, h) << "\n\n";
    }
    return 0;
}