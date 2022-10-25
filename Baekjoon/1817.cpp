#include <iostream>
using namespace std;

int b[50];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> b[i];

    int ans = 0, sum = 0, idx = 0;
    while(idx < n) {
        sum += b[idx++];

        while(sum < m && idx < n) {
            sum += b[idx];
            if(sum > m) break;
            idx++;
        }
        sum = 0;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}