#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, t = 0, f = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int num = i;
    while (num % 2 == 0) {
      t++;
      num /= 2;
    }
    while (num % 5 == 0) {
      f++;
      num /= 5;
    }
  }
  cout << min(t, f) << '\n';
  return 0;
}
