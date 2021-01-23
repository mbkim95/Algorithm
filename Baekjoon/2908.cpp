#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  cout << (a > b ? a : b) << '\n';
  return 0;
}
