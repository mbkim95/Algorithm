#include <iostream>
using namespace std;

int n, v[64][64];

void compress(int x, int y, int size) {
  bool is_same = true;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (v[y + i][x + j] != v[y][x]) {
        is_same = false;
        break;
      }
    }
    if (!is_same) break;
  }
  if (is_same) printf("%d", v[y][x]);
  else {
    printf("(");
    int s = size / 2;
    for (int i = 0; i < 4; i++) compress(x + (i % 2) * s, y + (i / 2) * s, s);
    printf(")");
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%1d", &v[i][j]);
  compress(0, 0, n);
  printf("\n");
  return 0;
}
