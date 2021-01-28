#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << (a ^ c ^ e) << ' ' << (b ^ d ^ f) << '\n';
  return 0;
} 
