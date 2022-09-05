#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;

void dfs(int idx, int health, int joyful, vector<int>& lose, vector<int>& joy) {
    if(idx == n) {
        ans = max(ans, joyful);
        return;
    }

    dfs(idx+1, health, joyful, lose, joy);
    if(health - lose[idx] > 0) dfs(idx+1, health - lose[idx], joyful + joy[idx], lose, joy);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> lose(n), joy(n);
    for(int i=0; i<n; i++) cin >> lose[i];
    for(int i=0; i<n; i++) cin >> joy[i];
    dfs(0, 100, 0, lose, joy);
    cout << ans << '\n';
    return 0;
}