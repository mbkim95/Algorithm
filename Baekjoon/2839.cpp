#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 987654321;
  for (int i = 0; i <= 5000; i++) {
    for (int j = 0; j <= 5000; j++) {
      int tmp = 5 * i + 3 * j;
      if(tmp > n) break;
      if (tmp == n) {
        ans = min(ans, i + j);
      }
    }
  }
  if(ans == 987654321) cout << "-1\n";
  else cout << ans << '\n';
  return 0;
}
