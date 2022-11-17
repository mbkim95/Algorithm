#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int mw, mb, tw, tb, pw, pb;
    cin >> mw >> mb;
    cin >> tw >> tb;
    cin >> pw >> pb;
    int a = min(tb, min(mw, pw));
    int b = min(tw, min(mb, pb));
    if (abs(a - b) > 1) cout << 2 * min(a, b) + 1 << '\n';
    else cout << a + b << '\n';
    return 0;
}