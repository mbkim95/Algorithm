#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;

    while(c--) {
        int n, t = 0,  f = 0;
        cin >> n;

        for(int i=2; i<=n; i*=2) t += n / i;
        for(int i=5; i<=n; i*=5) f += n / i;
        cout << min(t, f) << '\n';
    }
    return 0;
}