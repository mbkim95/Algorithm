#include <iostream>
using namespace std;

int n, p[200][200], b, w;

void check(int x, int y, int size) {
  bool find = true;
  int c = p[y][x];
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      if (p[y + i][x + j] != c) {
        find = false;
        break;
      }
      if (!find) break;
    }
  if (find) {
    if (c == 0) w++;
    else b++;
    return;
  }

  check(x, y, size / 2);
  check(x + size / 2, y, size / 2);
  check(x, y + size / 2, size / 2);
  check(x + size / 2, y + size / 2, size / 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> p[i][j];
  check(0, 0, n);
  cout << w << '\n' << b << '\n';
  return 0;
}
