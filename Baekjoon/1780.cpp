#include <iostream>
using namespace std;

int n, p[3000][3000], m, z, o;

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
    if (c == -1) m++;
    else if(c == 0) z++;
    else o++;
    return;
  }

  int s = size / 3;
  for(int i=0; i<9; i++)  check(x + (i % 3) * s, y + (i / 3) * s, s);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> p[i][j];
  check(0, 0, n);
  cout << m << '\n' << z << '\n' << o << '\n';
  return 0;
}
