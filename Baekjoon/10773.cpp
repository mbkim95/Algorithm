#include <iostream>
#include <stack>
using namespace std;

int main() {
  int k, tmp, ans = 0;
  stack<int> st;
  cin >> k;
  while (k--) {
    cin >> tmp;
    if (tmp == 0) st.pop();
    if (tmp != 0) st.push(tmp);
  }
  while(st.size() > 0){
    ans += st.top();
    st.pop();
  }
  cout << ans << '\n';
  return 0;
}
