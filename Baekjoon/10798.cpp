#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char c[5][16];

int main() {
  int len = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%s", c[i]);
    len = max(len, (int)strlen(c[i]));
  }
  for (int j = 0; j < len; j++)
    for (int i = 0; i < 5; i++)
      if (c[i][j] != '\0') cout << c[i][j];
  cout << '\n';
  return 0;
}