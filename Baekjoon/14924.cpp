#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s, t, d;
    cin >> s >> t >> d;
    cout << d/(s*2) * t << '\n';
    return 0;
}