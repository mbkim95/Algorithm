#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> map;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    map[tmp]++;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    cout << map[tmp] << ' ';
  }
  cout << '\n';
  return 0;
}
