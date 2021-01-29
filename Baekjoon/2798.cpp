#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, card[300000];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> card[i];
  for (int i = 0; i < n - 2; i++)
    for (int j = i + 1; j < n - 1; j++)
      for (int k = j + 1; k < n; k++) {
        if (card[i] + card[j] + card[k] == m) {
          ans = m;
          break;
        }
        if (card[i] + card[j] + card[k] < m) {
          ans = max(ans, card[i] + card[j] + card[k]);
        }
      }
  cout << ans << '\n';
  return 0;
}
