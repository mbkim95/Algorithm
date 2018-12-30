#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int L, R, C;
vector<vector<vector<char>>> B;
vector<vector<vector<bool>>> visited;
const int dx[6] = { -1, 1, 0, 0, 0, 0 }, dy[6] = { 0, 0, -1, 1, 0, 0 }, dz[6] = { 0, 0, 0, 0, -1, 1 };

bool inRange(int x, int y, int z) {
	return (0 <= x && x < C) && (0 <= y && y < R) && (0 <= z && z < L);
}

int bfs() {
	tuple<int, int, int> start, finish;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (B[i][j][k] == 'S') {
					start = make_tuple(k, j, i);
				}
				else if (B[i][j][k] == 'E') {
					finish = make_tuple(k, j, i);
				}
			}
		}
	}

	queue<tuple<int, int, int>> q;
	visited[get<2>(start)][get<1>(start)][get<0>(start)] = 1;
	q.push(start);
	int minute = 0;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			tuple<int, int, int> tmp = q.front();
			q.pop();

			if (tmp == finish)
				return minute;

			for (int i = 0; i < 6; i++) {
				int nextX = get<0>(tmp) + dx[i];
				int nextY = get<1>(tmp) + dy[i];
				int nextZ = get<2>(tmp) + dz[i];
				if (inRange(nextX, nextY, nextZ) && !visited[nextZ][nextY][nextX] && B[nextZ][nextY][nextX] != '#') {
					q.push(make_tuple(nextX, nextY, nextZ));
					visited[nextZ][nextY][nextX] = 1;
				}
			}
		}
		minute++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> L >> R >> C;

	while (!(L == 0 && R == 0 && C == 0)) {
		B = vector<vector<vector<char>>>(L, vector<vector<char>>(R, vector<char>(C, 0)));
		visited = vector<vector<vector<bool>>>(L, vector<vector<bool>>(R, vector<bool>(C, 0)));

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> B[i][j][k];
				}				
			}
		}
		int ans = bfs();
		ans == -1 ? cout << "Trapped!" << '\n' : cout << "Escaped in " << ans << " minute(s).\n";
		cin >> L >> R >> C;
	}
	return 0;
}