#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int s_x, s_y, f_x, f_y;
vector<vector<char>> map;
vector<pair<int, int>> water;

bool inRange(int x, int y) {
	return (0 <= x && x < C) && (0 <= y && y < R);
}

int bfs() {
	const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;
	q1.push(make_pair(s_x, s_y));
	for (int i = 0; i < water.size(); i++)
		q2.push(water[i]);
	int time = 0;
	while (!q1.empty()) {
		int size = q2.size();

		
		while (size--) {
			pair<int, int> tmp = q2.front();
			q2.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = tmp.first + dx[i];
				int nextY = tmp.second + dy[i];
				if (inRange(nextX, nextY) && (map[nextY][nextX] == '.' || map[nextY][nextX] == 'S')) {
					map[nextY][nextX] = '*';
					q2.push(make_pair(nextX, nextY));
				}
			}
		}
		size = q1.size();
		while (size--) {
			pair<int, int> tmp = q1.front();
			q1.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = tmp.first + dx[i];
				int nextY = tmp.second + dy[i];
				if (inRange(nextX, nextY) && (map[nextY][nextX] == '.' || map[nextY][nextX] == 'D')) {
					if (map[nextY][nextX] == 'D')
						return time + 1;
					else {
						q1.push(make_pair(nextX, nextY));
						map[nextY][nextX] = 'S';
					}
				}
			}
		}
		time++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	map = vector<vector<char>>(R, vector<char>(C, 0));
	for(int i=0; i<R; i++)
		for (int j = 0; j < C; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'S') {
				s_x = j;
				s_y = i;
			}
			else if (tmp == 'D') {
				f_x = j;
				f_y = i;
			}
			else if (tmp == '*') {
				water.push_back(make_pair(j, i));
			}
			map[i][j] = tmp;
		}
	int ans = bfs();
	ans == -1 ? cout << "KAKTUS\n" : cout << ans << '\n';
	return 0;
}