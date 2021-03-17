#include <iostream>
#include <stack>
using namespace std;

int n, num[1000001], ans[1000001];
stack<int> st;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= num[i]) st.pop();

    if (st.empty()) ans[i] = -1;
    else ans[i] = st.top();
    st.push(num[i]);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
