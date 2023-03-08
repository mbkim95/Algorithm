#include <iostream>
using namespace std;

int main() {
    int t1, t2, f1, f2, s1, s2, p1, p2, c1, c2;
    cin >> t1 >> f1 >> s1 >> p1 >> c1;
    cin >> t2 >> f2 >> s2 >> p2 >> c2;
    cout << 6 * t1 + 3 * f1 + 2 * s1 + p1 + 2 * c1 << ' ' << 6 * t2 + 3 * f2 + 2 * s2 + p2 + 2 * c2 << '\n';
    return 0;
}