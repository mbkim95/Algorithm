#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m, num[8], chk[8];
vector<int> ans;
set<string> s;

void dfs(int idx) {
  if (ans.size() == m) {
    string tmp = "";
    for (int i : ans) tmp += (to_string(i) + " ");
    if (s.find(tmp) == s.end()) {
      cout << tmp << '\n';
      s.insert(tmp);
    }
    return;
  }

  for (int i = 0; i < n; i++) {
    if(chk[i]) continue;
    chk[i] = 1;
    ans.push_back(num[i]);
    dfs(i);
    ans.pop_back();
    chk[i] = 0;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);
  dfs(-1);
  return 0;
}