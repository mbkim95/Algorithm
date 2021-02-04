#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101][101];

int solve(int a, int b, int c) {
  if (dp[a + 50][b + 50][c + 50] != -1) return dp[a + 50][b + 50][c + 50];
  if (a <= 0 || b <= 0 || c <= 0) return dp[a + 50][b + 50][c + 50] = 1;
  if (a > 20 || b > 20 || c > 20)
    return dp[a + 50][b + 50][c + 50] = solve(20, 20, 20);
  if (a < b && b < c)
    return dp[a + 50][b + 50][c + 50] =
               solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
  return dp[a + 50][b + 50][c + 50] =
             solve(a - 1, b, c) + solve(a - 1, b - 1, c) +
             solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main() {
  int a, b, c;
  memset(dp, -1, sizeof(dp));

  while (true) {
    scanf("%d %d %d", &a, &b, &c);
    if (a == -1 && b == -1 && c == -1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
  }
  return 0;
}
