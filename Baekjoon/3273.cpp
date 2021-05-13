#include <iostream>
#include <algorithm>
using namespace std;

int n, x, num[100001];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  cin >> x;

  sort(num, num + n);
  
  int s = 0, e = n - 1, ans = 0;
  while(s < e){
    int a = num[s], b = num[e];
    if(a + b == x) {
      e--;
      ans++;
    }else if(a + b < x) s++;
    else e--;
  }
  cout << ans << '\n';
  return 0;
}