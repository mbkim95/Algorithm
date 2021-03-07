#include <iostream>
using namespace std;

int n;
long long c[100001], w[100001];

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> c[i];

  int cur = 0;
  long long ans = 0;
  while (cur < n - 1) {
    long long move = w[cur];
    bool is_end = false;
    for (int i = cur + 1; i < n; i++) {
      if (c[cur] > c[i]) {
        ans += (c[cur] * move);
        cur = i;
        break;
      }
      if (i == n - 1) is_end = true;
      move += w[i];
    }
    if (is_end) {
      ans += (c[cur] * move);
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
