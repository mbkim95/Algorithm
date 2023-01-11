#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c;

int main() {
    cin >> n;
    cin >> a >> b >> c;
    cout << min(a, n) + min(b, n) + min(c, n) << '\n';
    return 0;
}