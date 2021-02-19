#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;
  int g = gcd(a, b);
  cout << g << '\n' << (a / g) * (b / g) * g << '\n';
  return 0;
}
