#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num, ans;

void dfs(int idx) {
  if (ans.size() == m) {
    for (int i : ans) cout << i << ' ';
    cout << '\n';
    return;
  }

  for (int i = idx + 1; i < n; i++) {
    ans.push_back(num[i]);
    dfs(i);
    ans.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    num.push_back(tmp);
  }
  sort(num.begin(), num.end());
  dfs(-1);
  return 0;
}