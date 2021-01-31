#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int n, m;

void dfs(int idx){
  if(ans.size() == m){
    for(int i : ans) cout << i << ' ';
    cout << '\n';
    return;
  }
  
  for(int i=1; i<=n; i++){
    ans.push_back(i);
    dfs(i);
    ans.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    ans.push_back(i);
    dfs(i);
    ans.pop_back();
  }
  return 0;
}
