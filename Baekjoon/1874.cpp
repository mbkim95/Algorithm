#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> st;
vector<char> v;

int main() {
  bool is_possible = true;
  cin >> n;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    while (tmp >= cur) {
      st.push(cur++);
      v.push_back('+');
    }
    if (!st.empty() && st.top() == tmp) {
      st.pop();
      v.push_back('-');
    } else is_possible = false;
  }
  if (is_possible) for (char c : v) cout << c << '\n';
  else cout << "NO\n";
  return 0;
}
