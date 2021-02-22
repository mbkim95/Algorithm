#include <iostream>
#include <map>
using namespace std;

int main() {
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      m[s2]++;
    }
    int ans = 1;
    for (auto it : m) {
      ans *= (it.second + 1);
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}
