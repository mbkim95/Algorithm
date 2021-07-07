#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 1; i <= n; i++) v[i - 1] = i;
  do {
    for(int i : v) cout << i << ' ';
    cout << '\n';
  }while(next_permutation(v.begin(), v.end()));
  return 0;
}