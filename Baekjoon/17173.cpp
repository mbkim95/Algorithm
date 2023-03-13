#include <iostream>
using namespace std;

int n, m, ans, k[1000];
bool num[1001];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) cin >> k[i];
    for(int i=0; i<m; i++) {
        for(int j=k[i]; j<=n; j+=k[i]) {
            if(!num[j]) {
                num[j] = true;
                ans += j;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}