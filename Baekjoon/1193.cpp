#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  int cnt = 1;
  while (cnt * (cnt + 1) / 2 < x) cnt++;
  int pos = x - ((cnt - 1) * cnt / 2);
  if (cnt % 2) cout << cnt + 1 - pos << '/' << pos << '\n';
  else cout << pos << '/' << cnt + 1 - pos << '\n';
  return 0;
}
