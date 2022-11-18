#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w, h, p, q, t, x, y;
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    x = (p + t) % (2 * w);
    y = (q + t) % (2 * h);

    cout << w - abs(w - x) << ' ' << h - abs(h - y) << '\n';
    return 0;
}