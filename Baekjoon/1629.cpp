#include <iostream>
using namespace std;

long long a, b, c;

long long mul(long long n, long long m) {
  if (m == 0) return 1;
  if (m == 1) return n;
  if (m % 2 == 1) return mul(n, m - 1) * n;

  long long h = mul(n, m / 2);
  h %= c;
  return (h * h) % c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c;
  cout << mul(a, b) % c << '\n';
  return 0;
}
