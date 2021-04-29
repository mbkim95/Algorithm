#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    string cmd;
    int tmp;
    cin >> cmd;
    if (cmd == "push") {
      cin >> tmp;
      q.push(tmp);
    }
    if (cmd == "pop") {
      if (q.empty())
        cout << "-1\n";
      else {
        cout << q.front() << '\n';
        q.pop();
      }
    }
    if (cmd == "front") {
      if(q.empty()) cout << "-1\n";
      else cout << q.front() << '\n';
    }
    if (cmd == "back") {
      if (q.empty()) cout << "-1\n";
      else cout << q.back() << '\n';
    }
    if (cmd == "size") cout << q.size() << '\n';
    if (cmd == "empty") cout << q.empty() << '\n';
  }
  return 0;
}