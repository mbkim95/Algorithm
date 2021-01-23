#include <iostream>
using namespace std;

int num[101];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
      scanf("%1d", &num[i]);
      sum += num[i];
  }
  printf("%d\n", sum);
  return 0;
}
