#include <deque>
#include <iostream>
using namespace std;

int n;
string cmd, number;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    cin >> cmd >> n >> number;
    deque<int> dq;
    number = number.substr(1, number.size() - 2);

    int tmp = 0;
    for (char c : number) {
      if (c == ',') {
        dq.push_back(tmp);
        tmp = 0;
        continue;
      }
      tmp = 10 * tmp + (c - '0');
    }
    if (tmp != 0) dq.push_back(tmp);

    bool isPossible = true;
    bool reverse = false;
    for (char c : cmd) {
      if (c == 'R')
        reverse = !reverse;
      else {
        if (dq.empty()) {
          isPossible = false;
          break;
        }
        if (reverse)
          dq.pop_back();
        else
          dq.pop_front();
      }
    }

    if (!isPossible)
      cout << "error\n";
    else {
      cout << '[';
      while (dq.size() > 1) {
        if (reverse) {
          cout << dq.back() << ',';
          dq.pop_back();
        } else {
          cout << dq.front() << ',';
          dq.pop_front();
        }
      }
      if (dq.size() != 0) cout << dq.front();
      cout << "]\n";
    }
  }
  return 0;
}
