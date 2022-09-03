#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long ans = LONG_MAX;
vector<pair<int, int>> ingredient;

void solve(int i, long long s, long long b) {
    if (i == ingredient.size()) {
        if(s == 1 && b == 0) return;
        long long tmp = abs(s - b);
        ans = ans > tmp ? tmp : ans;
        return;
    }

    solve(i + 1, s * ingredient[i].first, b + ingredient[i].second);
    solve(i + 1, s, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, b;
        cin >> s >> b;
        ingredient.push_back({s, b});
    }

    solve(0, 1, 0);
    cout << ans << '\n';
    return 0;
}