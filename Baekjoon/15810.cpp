#include <iostream>
#include <algorithm>
using namespace std;

int n, m, b[1000000], cnt;
long long ans = 1000000000000;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> b[i];
    long long s = 0, e = 1000000000000;

    while(s <= e) {
        long long mid = (s + e) / 2, cnt = 0;

        for(int i=0; i<n; i++) cnt += (mid / b[i]);

        if(cnt >= m) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}