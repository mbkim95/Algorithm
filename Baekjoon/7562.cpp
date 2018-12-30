#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, cur_x, cur_y, fin_x, fin_y;
vector<vector<int>> map, visited;
const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }, dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(cur_x, cur_y));
	visited[cur_y][cur_x] = 1;
	int depth = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			pair<int, int> tmp = q.front();
			q.pop();

			if (tmp.first == fin_x && tmp.second == fin_y)
				return depth;

			for (int j = 0; j < 8; j++) {
				int nextX = tmp.first + dx[j];
				int nextY = tmp.second + dy[j];
				if (inRange(nextX, nextY) && !visited[nextY][nextX]) {
					visited[nextY][nextX] = 1;
					q.push(make_pair(nextX, nextY));
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
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> cur_x >> cur_y;
		cin >> fin_x >> fin_y;
		map = vector<vector<int>>(n, vector<int>(n, 0));
		visited = vector<vector<int>>(n, vector<int>(n, 0));
		cout << bfs() << '\n';
	}
	return 0;
}