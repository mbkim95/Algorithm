#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, m, ans;
deque<int> dq;

int main() {
  cin >> n >> m;
  for(int i=1; i<=n; i++) dq.push_back(i);

  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    int left_move = 0, right_move = 0;
    while (dq.front() != tmp) {
      dq.push_back(dq.front());
      dq.pop_front();
      left_move++;
    }
    for (int i = 0; i < left_move; i++) {
      dq.push_front(dq.back());
      dq.pop_back();
    }
    while (dq.front() != tmp) {
      dq.push_front(dq.back());
      dq.pop_back();
      right_move++;
    }
    dq.pop_front();
    ans += min(left_move, right_move);
  }
  cout << ans << '\n';
  return 0;
}
