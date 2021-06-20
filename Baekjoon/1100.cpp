#include <iostream>
using namespace std;

int main() {
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;
      if (c == 'F') {
        if (!(i % 2) && !(j % 2)) ans++;
        if (i % 2 && j % 2) ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}