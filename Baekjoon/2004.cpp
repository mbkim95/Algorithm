#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long t, f;

void calculate(int num, int v) {
  for (long long i = 2; i <= num; i *= 2) t += (num / i) * v;
  for (long long i = 5; i <= num; i *= 5) f += (num / i) * v;
}

int main() {
  cin >> n >> m;
  calculate(n, 1);
  calculate(n - m, -1);
  calculate(m, -1);
  cout << min(t, f) << '\n';
  return 0;
}
