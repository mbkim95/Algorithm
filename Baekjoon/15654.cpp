#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num[8], chk[8];
vector<int> ans;

void dfs(int cur) {
  if(ans.size() == m){
    for(int i : ans) cout << i << ' ';
    cout << '\n';
    return;
  }

  for(int i=0; i < n; i++){
    if(!chk[i]){
      chk[i] = 1;
      ans.push_back(num[i]);
      dfs(i);
      ans.pop_back();
      chk[i] = 0;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);
  dfs(0);
  return 0;
}