#include <iostream>
#include <deque>
using namespace std;

int main() {
  int n, tmp;
  deque<int> dq;
  cin >> n;
  string cmd;
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "push_front") {
      cin >> tmp;
      dq.push_front(tmp);
    } else if (cmd == "push_back") {
      cin >> tmp;
      dq.push_back(tmp);
    } else if (cmd == "pop_front") {
      if (dq.empty())
        cout << "-1\n";
      else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    } else if (cmd == "pop_back") {
      if (dq.empty())
        cout << "-1\n";
      else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    } else if (cmd == "size") {
      cout << dq.size() << '\n';
    } else if (cmd == "empty") {
      cout << dq.empty() << '\n';
    } else if (cmd == "front") {
      if (dq.empty())
        cout << "-1\n";
      else
        cout << dq.front() << '\n';
    } else if (cmd == "back") {
      if (dq.empty())
        cout << "-1\n";
      else
        cout << dq.back() << '\n';
    }
  }
  return 0;
}
