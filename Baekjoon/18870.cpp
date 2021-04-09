#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> n1, n2;
unordered_map<int, int> m;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++){
    int tmp;
    cin >> tmp;
    n1.push_back(tmp);
    n2.push_back(tmp);
  }
  sort(n2.begin(), n2.end());
  

  int cnt = 1;
  for(int i : n2) {
    if(m[i] == 0) m[i] = cnt++;
  }
  for(int i : n1) cout << m[i] - 1 << ' ';
  cout << '\n';
  return 0;
}
