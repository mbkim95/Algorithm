#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, w[100001], s, e, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i];
  sort(w, w + n);

  s = a = 0, e = b = n - 1;
  while (s < e) {
    int sum = w[s] + w[e];
    if (abs(sum) < abs(w[a] + w[b])) a = s, b = e;
    else if (sum > 0) e--;
    else s++;
  }
  cout << w[a] << ' ' << w[b] << '\n';
  return 0;
}