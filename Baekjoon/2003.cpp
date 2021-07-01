#include <iostream>
using namespace std;

int n, m, a[10001], ans, l, r;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];

  long long sum = a[l];
  while(l <= r) {
    if(r == n) break;
    if(sum <= m || l == r) {
      if(sum == m) ans++;
      sum += a[++r];
    }
    else if(sum > m) sum -= a[l++];
  }
  cout << ans << '\n';
  return 0;
}