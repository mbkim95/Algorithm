#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > num;

pair<int, int> fibonacci(int n) {
  if (n == 0) return num[n] = make_pair(1, 0);
  else if (n == 1) return num[n] = make_pair(0, 1);
  else if(num[n].first != -1 && num[n].second != -1) return num[n];
  pair<int, int> l = fibonacci(n - 2);
  pair<int, int> r = fibonacci(n - 1);
  return num[n] = make_pair(l.first + r.first, l.second + r.second);
}

int main() {
  int t;
  cin >> t;
  num = vector<pair<int, int> >(41, make_pair(-1, -1));
  while (t--) {
	  int n;
	  cin >> n;
	  pair<int, int> result = fibonacci(n);
	  cout << result.first << ' ' << result.second << '\n';
  }
  return 0;
}
