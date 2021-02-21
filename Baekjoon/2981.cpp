#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, num[101];
vector<int> ans;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);

  int g = num[1] - num[0];
  for (int i = 2; i < n; i++) g = gcd(g, num[i] - num[i - 1]);
  for (int i = 2; i * i <= g; i++)
    if (g % i == 0) {
      if (g / i != i) ans.push_back(g / i);
      ans.push_back(i);
    }
  ans.push_back(g);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
