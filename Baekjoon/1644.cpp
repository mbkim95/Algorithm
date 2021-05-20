#include <iostream>
#include <vector>
#include <cstring>
#define MAX 4000000
using namespace std;

int n;
bool is_prime[MAX + 1];
vector<int> num;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  memset(is_prime, true, sizeof(is_prime));
  is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = 2; i * j <= n; j++) {
        is_prime[i * j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++)
    if (is_prime[i]) num.push_back(i);

  int l = 0, r = 0, ans = 0, sum = 0;
  if(num.size() != 0) sum = num[l];

  while (l <= r) {
    if (r >= num.size()) break;
    if (sum <= n) {
      if (sum == n) ans++;
      sum += num[++r];
    } else
      sum -= num[l++];
  }
  cout << ans << '\n';
  return 0;
}