#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;

  while (t--) {
    ll x, y;
    cin >> x >> y;
    int a = (int)sqrt(y - x);
    if(a * a == y - x) cout << 2 * a - 1 << '\n';
    else if(a * a < y - x && y - x <= a * a + a) cout << 2 * a << '\n';
    else cout << 2 * a + 1 << '\n';
  }
  return 0;
}
