#include <algorithm>
#include <iostream>
using namespace std;

long long k, n, ans, l[10001];

int main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++) cin >> l[i];

  long long s = 1, e = l[0];
  for(int i=1; i<k; i++) e = max(e, l[i]);
  
  while(s <= e) {
    long long mid = (s + e) / 2;
    long long cnt = 0;
    for(int i=0;i <k; i++) cnt += l[i] / mid;
    if(cnt < n) e = mid -1;
    else{
      s = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans << '\n';
  return 0;
}
