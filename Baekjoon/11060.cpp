#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> a, visited;

int bfs() {
	visited = vector<int>(n, 987654321);
	queue<int> q;
	q.push(0);
	visited[0] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= a[cur]; i++) {
			if (cur + i >= n) break; // 범위를 벗어나면 멈춘다
			if (visited[cur + i] > visited[cur] + 1) {
				visited[cur + i] = visited[cur] + 1;
				q.push(cur + i);
			}
		}
	}

	if (visited[n - 1] == 987654321) return -1;
	else return visited[n - 1];
}

int main() {
	cin >> n;
	a = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << bfs() << '\n';
	return 0;
}