#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<int> num, ans;
set<string> s;

void dfs(int idx, int cnt) {
  if (cnt == m) {
    string str = "";
    for (int i : ans) str += to_string(i) + " ";
    if (s.find(str) == s.end()) {
      s.insert(str);
      cout << str << '\n';
    }
    return;
  }

  for (int i = idx; i < n; i++) {
    ans.push_back(num[i]);
    dfs(i, cnt + 1);
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
  dfs(0, 0);
  return 0;
}