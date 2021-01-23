#include <iostream>
using namespace std;

bool rest[42];

int main() {
  for (int i = 0; i < 10; i++) {
    int tmp;
    cin >> tmp;
    rest[tmp % 42] = true;
  }
  int ans = 0;
  for (int i = 0; i < 42; i++)
    if (rest[i]) ans++;
  cout << ans << '\n';
  return 0;
}
