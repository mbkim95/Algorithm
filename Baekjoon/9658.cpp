#include <iostream>
using namespace std;

int n, g[1001];

int main() {
  cin >> n;
  g[2] = g[4] = 1;

  for(int i=5; i<=n; i++) g[i] = !g[i-1] | !g[i-3] | !g[i-4];
  if(g[n] == 0) cout << "CY\n";
  else cout << "SK\n";
}