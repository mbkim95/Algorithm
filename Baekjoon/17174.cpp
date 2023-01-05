#include <iostream>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    ans += n;
    while(n / m > 0) {
        ans += n / m;
        n /= m;
    }
    cout << ans << '\n';
    return 0;
}