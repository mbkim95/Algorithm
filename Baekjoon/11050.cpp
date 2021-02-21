#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 1;
  for (int i = 0; i < k; i++) ans *= (n - i);
  for (int i = k; i > 0; i--) ans /= i;
  cout << ans << '\n';
  return 0;
}
