#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
map<string, int> dict;
vector<string> ans;

int main() {
  cin >> n >> m;
  for(int i=0; i<n+m; i++) {
    string name;
    cin >> name;
    dict[name]++;
  }
  for(auto it : dict) {
    if(it.second > 1) ans.push_back(it.first);
  }
  cout << ans.size() << '\n';
  for(auto it : ans) cout << it << '\n';
  return 0;
}