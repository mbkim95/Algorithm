#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, num[1001];
vector<int> ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  reverse(num, num + n);
  ans.push_back(num[0]);

  for(int i=1; i<n; i++) {
    if(ans.back() < num[i]) ans.push_back(num[i]);
    else{
      auto it = lower_bound(ans.begin(), ans.end(), num[i]);
      *it = num[i];
    }
  }
  cout << ans.size() << '\n';
  return 0;
}