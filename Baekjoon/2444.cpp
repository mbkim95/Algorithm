#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      for (int j = 1; j <= n - i; j++) cout << ' ';
      for (int j = 1; j <= 2 * i - 1; j++) cout << '*';
      cout << '\n';
    } else {
      for (int j = 1; j <= i - n; j++) cout << ' ';
      for (int j = 1; j <= 4 * n - 2 * i - 1; j++) cout << '*';
      cout << '\n';
    }
  }
  return 0;
}