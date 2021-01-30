#include <iostream>
#include <algorithm>
using namespace std;

char board[50][50];

int calculate(char cut[8][8]) {
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char tmp = cut[i][j];
      if (!(i % 2) && !(j % 2)) {
        if (tmp != 'W') ans1++;
		else ans2++;
      } else if (!(i % 2) && j % 2) {
        if (tmp != 'B') ans1++;
        else ans2++;
      } else if (i % 2 && !(j % 2)) {
        if (tmp != 'B') ans1++;
        else ans2++;
      } else {
        if (tmp != 'W') ans1++;
        else ans2++;
      }
    }
  }
  return min(ans1, ans2);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];

  int ans = 987654321;
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      char tmp[8][8];
      for (int k = 0; k < 8; k++)
        for (int l = 0; l < 8; l++) tmp[k][l] = board[i + k][j + l];
      ans = min(ans, calculate(tmp));
    }
  }
  cout << ans << '\n';
  return 0;
}
