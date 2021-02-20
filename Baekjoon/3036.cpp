#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int n, r, tmp;
  cin >> n >> r;
  for (int i = 1; i < n; i++) {
    cin >> tmp;
    int g = gcd(r, tmp);
    cout << r / g << '/' << tmp / g << '\n';
  }
  return 0;
}
