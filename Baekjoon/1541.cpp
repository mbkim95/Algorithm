#include <iostream>
using namespace std;

int num[50];
bool under[50];

int main() {
  string str;
  cin >> str;

  string tmp = "";
  int idx = 0;
  for (char c : str) {
    if (c == '+' || c == '-') {
      int number = stoi(tmp);
      num[idx] = number;
      if (c == '-') under[idx + 1] = true;
      idx++;
      tmp = "";
      continue;
    }
    tmp += c;
  }
  int number = stoi(tmp);
  num[idx] = number;
  idx++;

  int index = 0;
  for (int i = 0; i < idx; i++) {
    if (under[i]) {
      int sum = 0;
      for (int j = index; j < i; j++) {
        sum += num[j];
        num[j] = 0;
      }
      num[index] = sum;
      index = i;
    }
  }
  int sum = 0;
  for (int j = index; j < idx; j++) {
    sum += num[j];
    num[j] = 0;
  }
  num[index] = sum;

  int ans = 0;
  for (int i = 0; i < idx; i++)
    if (under[i])
      ans -= num[i];
    else
      ans += num[i];
  cout << ans << '\n';
  return 0;
}
