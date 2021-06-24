#include <algorithm>
#include <iostream>
using namespace std;

int n, a[51], b[51];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n, greater<int>());
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i] * b[i];
  cout << sum << '\n';
  return 0;
}