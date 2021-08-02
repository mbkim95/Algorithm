#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> str(n);
  for (int i = 0; i < n; i++) cin >> str[i];
  string ans = str[0];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < ans.length(); j++)
      if (ans[j] != str[i][j]) ans[j] = '?';
  cout << ans << '\n';
  return 0;
}