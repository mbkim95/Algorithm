#include <iostream>
using namespace std;

int n, k, num[11];

int main() {
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> num[i];

  while (k) {
    for (int i = n - 1; i >= 0; i--) {
      if (k / num[i] > 0) {
        ans += k / num[i];
        k %= num[i];
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
