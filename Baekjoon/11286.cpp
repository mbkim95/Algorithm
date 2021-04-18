#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;

struct compare{
  bool operator()(int a, int b){
    if(abs(a) == abs(b)) return a < b;
    return abs(a) > abs(b);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, compare> pq;
  cin >> n;
  while (n--) {
    cin >> x;
    if (x == 0) {
      if (pq.empty()) cout << "0\n";
      else {
        cout << -pq.top() << '\n';
        pq.pop();
      }
    } else pq.push(-x);
  }
  return 0;
}