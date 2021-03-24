#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> num(n);
  for(int i=0; i<n; i++) cin >> num[i];

  vector<int> ans;
  ans.push_back(num[0]);

  for(int i=1; i<n; i++){
    if(num[i] > ans.back()) ans.push_back(num[i]);
    else{
      auto it = lower_bound(ans.begin(), ans.end(), num[i]);
      *it = num[i];
    }
  }
  cout << ans.size() << '\n';
  return 0;
}
