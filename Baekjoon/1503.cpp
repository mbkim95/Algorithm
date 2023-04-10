#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool num[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = INT_MAX;

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        num[tmp] = true;
    }

    for(int x=1; x<=1001; x++) {
        if(num[x]) continue;
        for(int y=1; y<=1001; y++) {
            if(num[y]) continue;
            for(int z=1; z<=1001; z++) {
                if(num[z]) continue;
                ans = min(ans, abs(n - (x * y * z)));
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}