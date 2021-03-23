#include <algorithm>
#include <iostream>
using namespace std;

int n, k, ans;

int main() {
  cin >> n >> k;

  int l = 1, r = k;

  while (l <= r) {
    long long cnt = 0;
    int mid = (l + r) / 2;

    for (int i = 1; i <= n; i++) cnt += min(mid / i, n);
    if (cnt < k) l = mid + 1;
    else {
      ans = mid;
      r = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
