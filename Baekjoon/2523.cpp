#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      for (int j = 1; j <= i; j++) cout << '*';
      cout << '\n';
    } else {
      for (int j = 1; j <= 2 * n - i; j++) cout << '*';
      cout << '\n';
    }
  }
  return 0;
}