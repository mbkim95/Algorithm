#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<int> &num, vector<bool> &visited, int cnt) {
    int size = num.size();
    if (cnt == num.size() - 2) return num.front() * num.back();

    int ret = 0;

    for (int i = 1; i < size - 1; i++) {
        if (!visited[i]) {
            int l, r;
            for (l = i - 1; l >= 0; l--) if (!visited[l]) break;
            for (r = i + 1; r < size; r++) if (!visited[r]) break;

            if (l == -1 || r == size) continue;

            visited[i] = true;
            ret = max(ret, (num[l] * num[r]) + dfs(num, visited, cnt + 1));
            visited[i] = false;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0, cnt = 0;
    cin >> n;
    vector<int> num(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) cin >> num[i];
    cout << dfs(num, visited, 1) << '\n';
    return 0;
}