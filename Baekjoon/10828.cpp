#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  stack<int> st;
  cin >> n;

  while (n--) {
    int value;
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      cin >> value;
      st.push(value);
    } else if (cmd == "pop") {
      if (st.empty())
        cout << "-1\n";
      else {
        cout << st.top() << '\n';
        st.pop();
      }
    } else if (cmd == "size") {
      cout << st.size() << '\n';
    } else if (cmd == "empty") {
      if (st.empty())
        cout << "1\n";
      else
        cout << "0\n";
    } else if (cmd == "top") {
      if (st.empty())
        cout << "-1\n";
      else
        cout << st.top() << '\n';
    }
  }
  return 0;
}
