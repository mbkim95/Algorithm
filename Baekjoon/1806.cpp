#include <iostream>
#include <algorithm>
using namespace std;

int n, s, l, r, num[100001];

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> num[i];

  l = r = 0;
  int sum = num[l], ans = n + 1;

  while (l <= r) {
    if (r == n) break;
    if (sum < s) {
      r++;
      sum += num[r];
    } else {
      ans = min(ans, r - l + 1);
      sum -= num[l];
      l++;
    }
  }
  if (ans == n + 1)
    cout << "0\n";
  else
    cout << ans << '\n';
  return 0;
}