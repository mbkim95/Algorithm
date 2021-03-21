#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, t[1000001];

int main() {
  cin >> n >> m;

  int l = 1, r = 1;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    r = max(r, t[i]);
  }
  while (l <= r) {
    long long sum = 0;
    int mid = (l + r) / 2;

    for (int i = 0; i < n; i++) {
      if (mid < t[i]) sum += (t[i] - mid);
    }

    if (sum < m) r = mid - 1;
    else {
      l = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans << '\n';
  return 0;
}
