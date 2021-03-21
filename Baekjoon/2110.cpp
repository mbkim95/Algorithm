#include <iostream>
#include <algorithm>
using namespace std;

int n, c, ans, x[200001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> x[i];

  sort(x, x + n);
  int l = 1, r = x[n - 1] - x[0];

  while (l <= r) {
    int mid = (l + r) / 2;
    int start = x[0];
    int cnt = 1;

    for (int i = 1; i < n; i++) {
      int d = x[i] - start;
      if (mid <= d) {
        cnt++;
        start = x[i];
      }
    }

    if (cnt < c)
      r = mid - 1;
    else {
      ans = max(ans, mid);
      l = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
