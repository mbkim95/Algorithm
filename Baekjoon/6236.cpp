#include <iostream>
#include <vector>
using namespace std;

int n, m, s[100001];

int count(int k) {
    int cnt = 1;
    int total = k;

    for (int i = 1; i <= n; i++) {
        if (k < s[i]) return -1;
        if (total < s[i]) {
            cnt++;
            total = k;
        }
        total -= s[i];
    }
    return cnt;
}

int binary_search() {
    int left = 1, right = 1000000000, ret = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        int c = count(mid);
        if (c == -1 || c > m) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ret = mid;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    cout << binary_search() << '\n';
    return 0;
}