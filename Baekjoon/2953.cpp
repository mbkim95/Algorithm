#include <iostream>
using namespace std;

int s[5], ans, idx = -1;
int main() {
  for(int i=0; i<5; i++){
    int sum = 0;
    for(int j=0; j<4; j++){
      int tmp;
      cin >> tmp;
      sum += tmp;
    }
    s[i] = sum;
    if(ans < s[i]){
      ans = s[i];
      idx = i;
    }
  }
  cout << idx + 1 << ' ' << ans << '\n';
  return 0;
}