#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    for(int i=1; i<=n; i++) {
        int tmp = i;
        while(tmp > 0) {
            int rest = tmp % 10;
            if(rest != 0 && rest % 3 == 0) ans++;
            tmp /= 10;
        }
    }
    cout << ans << '\n';
    return 0;
}