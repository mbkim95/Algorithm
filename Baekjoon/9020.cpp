#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

vector<bool> is_prime;

void precalc() {
  is_prime = vector<bool>(MAX + 1, true);
  is_prime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (!is_prime[i]) continue;
    for (int j = 2; i * j <= MAX; j++) is_prime[i * j] = false;
  }
}

int main() {
  precalc();
  int t;
  cin >> t;
  while(t--){
    int tmp;
    cin >> tmp;
    for(int i=tmp/2; i>=2; i--){
      if(is_prime[i] && is_prime[tmp-i]){
        cout << i << ' ' << tmp-i << '\n';
        break;
      }
    }
  }
  return 0;
}
