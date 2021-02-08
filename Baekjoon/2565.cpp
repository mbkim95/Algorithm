#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, dp[101];
vector<pair<int, int> > line;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    line.push_back(make_pair(l, r));
  }
  sort(line.begin(), line.end());
  int cnt = 0;
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (line[i].second > line[j].second && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    cnt = max(cnt, dp[i]);
  }
  cout << n - cnt << '\n';
  return 0;
}
