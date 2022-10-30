#include <iostream>
using namespace std;

int n, c, ans, p[100], chk[2000001];

int main() {
    cin >> n >> c;
    for(int i=0; i<n; i++) cin >> p[i];

    for(int i=0; i<n; i++) {
        int d = 1;
        while(d * p[i] <= c) {
            if(!chk[d * p[i]]) {
                ans++;
                chk[d * p[i]] = 1;
            }
            d++;
        }
    }
    cout << ans << '\n';
    return 0;
}