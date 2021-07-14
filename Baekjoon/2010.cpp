#include <iostream>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  for(int i=0; i<n; i++) {
    int tmp;
    cin >> tmp;
    ans += tmp;
  }
  cout << ans - n + 1 << '\n';
  return 0;
}