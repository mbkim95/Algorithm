#include <iostream>
#include <algorithm>
using namespace std;

int s, c, g[1000000];

bool find(int d) {
    int cnt = 0;
    for(int i=0; i<s; i++) cnt += g[i] / d;
    return cnt >= c;
}

int main() {
    cin >> s >> c;
    int l = 1, r = 1, cnt = 0;
    long long d = 0;
    long long sum = 0;
    for(int i=0; i<s; i++) {
        cin >> g[i];
        r = max(g[i], r);
        sum += g[i];
    }

    while(l <= r) {
        long long mid = (l + r) / 2;

        if(find(mid)) {
            d = max(d, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << sum - d * c << '\n';
}