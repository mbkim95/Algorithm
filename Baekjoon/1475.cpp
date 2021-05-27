#include <iostream>
#include <algorithm>
using namespace std;

int num[10];

int main() {
  string n;
  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    int tmp = n[i] - '0';
    if (tmp == 6 || tmp == 9) {
      if (num[6] <= num[9])
        num[6]++;
      else
        num[9]++;
    } else
      num[tmp]++;
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) ans = max(ans, num[i]);
  cout << ans << '\n';
  return 0;
}