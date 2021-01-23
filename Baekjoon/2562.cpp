#include <iostream>
using namespace std;

int main() {
  int max_num = 0, idx;
  for (int i = 1; i <= 9; i++) {
      int tmp;
      cin >> tmp;
      if(max_num < tmp){
          max_num = tmp;
          idx = i;
      }
  }
  cout << max_num << '\n' << idx << '\n';
  return 0;
}
