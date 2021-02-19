#include <iostream>
#include <algorithm>
using namespace std;

int n, num[51];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);
  cout << num[0] * num[n - 1] << '\n';
  return 0;
}
