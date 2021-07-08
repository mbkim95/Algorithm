#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int l = 0, r = s.length() - 1;
  bool is_right = true;
  while(l < r) {
    if(s[l] != s[r]) {
      is_right = false;
      break;
    }
    l++;
    r--;
  }
  if(is_right) cout << "1\n";
  else cout << "0\n";
  return 0;
}