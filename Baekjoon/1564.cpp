#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    long long f = 1;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        f *= i;
        while (f % 10 == 0) f /= 10;
        f %= 1000000000000;
    }
    string ans = to_string(f % 100000);
    while (ans.length() < 5) ans = '0' + ans;
    cout << ans << '\n';
    return 0;
}