#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int m, vector<int>& v, vector<int>& ans) {
  if (ans.size() == m) {
    for (int i : ans) cout << i << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    ans.push_back(v[i]);
    dfs(n, m, v, ans);
    ans.pop_back();
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  vector<int> ans;
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    ans.push_back(v[i]);
    dfs(n, m, v, ans);
    ans.pop_back();
  }
  return 0;
}