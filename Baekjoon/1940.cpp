#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int> g;

int main() {
    cin >> n;
    cin >> m;
    g.resize(n);
    for(int i=0; i<n; i++) cin >> g[i];
    sort(g.begin(), g.end());
    int s = 0, e = n - 1;
    while(s < e) {
        int sum = g[s] + g[e];
        if(sum > m) e--;
        else if(sum < m) s++;
        else {
            s++;
            e--;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}