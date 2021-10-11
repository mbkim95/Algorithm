#include <iostream>
using namespace std;

long long solution(int price, int money, int count) {
  long long p = price, c = count;
  long long answer = (p * c * (c + 1)) / 2 - money;
  if(answer <= 0) return 0;
  else return answer;
}

int main() {
  cout << solution(3, 20, 4) << '\n';
  return 0;
}