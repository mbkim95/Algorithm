#include <iostream>
using namespace std;

int n, a[1000001], b, c;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> b >> c;
  long long sum = 0;
  for(int i=0; i<n; i++) {
    sum += 1;
    if(a[i] - b > 0) sum += ((a[i] - b) % c == 0 ? (a[i] - b) / c : (a[i] - b) / c + 1);
  }
  cout << sum << '\n';
  return 0;
}