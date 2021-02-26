#include <iostream>
#include <stack>
using namespace std;

int main() {
  while (true) {
    stack<char> st;
    string str;
    getline(cin, str);

    if (str == ".") break;

    bool find = true;
    for (char c : str) {
      if (c == '(' || c == '[' || c == '{') st.push(c);
      if (c == ')' || c == ']' || c == '}') {
        if (c == ')' && (st.empty() || st.top() != '(')) {
          find = false;
          break;
        }
        if (c == ']' && (st.empty() || st.top() != '[')) {
          find = false;
          break;
        }
        if (c == '}' && (st.empty() || st.top() != '{')) {
          find = false;
          break;
        }
        st.pop();
      }
    }
    if (!find || !st.empty()) cout << "no\n";
    else cout << "yes\n";
  }
  return 0;
}
