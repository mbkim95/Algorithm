#include <iostream>
#include <queue>
using namespace std;


int main() {
  priority_queue<int> pq;
  int sum = 0;
  for(int i=0; i<7; i++) {
    int tmp;
    cin >> tmp;
    if(tmp % 2) {
      sum += tmp;
      pq.push(-tmp);
    }
  }
  if(pq.size() == 0) cout << "-1\n";
  else cout << sum << '\n' << -pq.top() << '\n';
  return 0;
}