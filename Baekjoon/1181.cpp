#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool cmp(string& a, string& b){
  if(a.length() == b.length()) return a < b;
  return a.length() < b.length();
}

int main(){
  int n;
  cin >> n;
  vector<string> w;
  set<string> s;
  for(int i=0; i<n; i++) {
    string tmp;
    cin >> tmp;
    if(s.find(tmp) != s.end()) continue;
    s.insert(tmp);
    w.push_back(tmp);
  }
  sort(w.begin(), w.end(), cmp);
  for(auto i : w) cout << i << '\n';
  return 0;
}
