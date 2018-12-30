#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;
vector<int> visited;

int bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	int depth = 0;
	const int dir[2] = { u, -d };

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int tmp = q.front();
			q.pop();

			if (tmp == g)
				return depth;

			for (int j = 0; j < 2; j++) {
				int next = tmp + dir[j];
				if (0 < next && next <= f && !visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
		depth++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;
	visited = vector<int>(f + 1, 0);
	int ans = bfs();
	ans == -1 ? cout << "use the stairs" << '\n' : cout << ans << '\n';
	return 0;
}