#include <iostream>
using namespace std;

const int num[10][4] = {{1, 1, 1, 1}, {2, 4, 8, 6}, {3, 9, 7, 1},
                        {4, 6, 4, 6}, {5, 5, 5, 5}, {6, 6, 6, 6},
                        {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1, 9, 1}};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int tmp = a % 10;
    int r = b % 4 == 0 ? 3 : b % 4 - 1;
    if (tmp == 0) cout << "10\n";
    else cout << num[tmp - 1][r] << '\n';
  }
  return 0;
}