#include <iostream>
using namespace std;

int factorial(int num) {
  if (num == 0) return 1;
  return num * factorial(num - 1);
}

int main() {
  int n;
  cin >> n;
  cout << factorial(n) << '\n';
  return 0;
}
