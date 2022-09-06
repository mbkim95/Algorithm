#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    cin >> l;
    vector<int> num(l);
    for (int i = 0; i < l; i++) cin >> num[i];
    cin >> n;
    sort(num.begin(), num.end());

    
    int idx = 0;

    int ans = 0;
    if(n < num[0]) {
        for(int i = 1; i < num[0]; i++) {
            for(int j = i + 1; j < num[0]; j++) {
                if(i <= n && n <= j) ans++;
            }
        }
    } else {
        for (idx = 0; idx < n - 1; idx++) if (num[idx] <= n && n <= num[idx + 1]) break;

        for (int i = num[idx] + 1; i <= num[idx + 1] - 1; i++) {
            for (int j = i + 1; j <= num[idx + 1] - 1; j++) {
                if (i <= n && n <= j) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}