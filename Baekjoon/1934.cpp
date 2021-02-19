#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    cout << (a / g) * (b / g) * g << '\n';
  }
  return 0;
}
