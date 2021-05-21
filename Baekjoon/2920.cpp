#include <iostream>
using namespace std;

int m[8];

int main() {
  bool is_ascending = true, is_descending = true;
  int prev, cur;
  cin >> prev;
  for(int i=0; i<7; i++) {
    cin >> cur;
    if(prev < cur) is_descending = false;
    if(cur < prev) is_ascending = false;
    prev = cur;
  }
  if(!is_ascending && !is_descending) cout << "mixed\n";
  else if(is_ascending) cout << "ascending\n";
  else cout << "descending\n";
  return 0;
}