#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        int ans = n % c == 0 ? n / c : n / c + 1;
        cout << ans << '\n';
    }
    return 0;
}