#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int cur = 1;
  vector<int> num;

  while (true) {
    bool end = false;
    for (int i = 0; i < cur; i++) {
      if (num.size() == 1000) {
        end = true;
        break;
      }
      num.push_back(cur);
    }
    cur++;
    if (end) break;
  }
  int sum = 0;
  for (int i = a - 1; i <= b - 1; i++) sum += num[i];
  cout << sum << '\n';
  return 0;
}