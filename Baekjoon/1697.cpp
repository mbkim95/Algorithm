#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int n, k, v[2 * MAX + 1];

int bfs() {
  queue<int> q;
  q.push(n);
  v[n] = 1;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == k) return v[cur] - 1;

    if (cur - 1 >= 0 && !v[cur - 1]) {
      q.push(cur - 1);
      v[cur - 1] = v[cur] + 1;
    }
    if (cur + 1 <= MAX && !v[cur + 1]) {
      q.push(cur + 1);
      v[cur + 1] = v[cur] + 1;
    }
    if (2 * cur <= 2 * MAX && !v[2 * cur]) {
      q.push(2 * cur);
      v[2 * cur] = v[cur] + 1;
    }
  }
  return -1;
}

int main() {
  cin >> n >> k;
  cout << bfs() << '\n';
  return 0;
}
