#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, n;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

void print(vector<vector<char>>& map) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) 
			cout << map[i][j];
		cout << '\n';
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < c) && (0 <= y && y < r);
}

void bfs(vector<vector<char>>& map, queue<pair<int, int>>& q) {
	int time = 1;
	while (true) {
		if (time == n)
			break;
		int size = q.size();
		if (time % 2 == 0) {
			while (size--) {
				int x = q.front().first;
				int y = q.front().second;
				map[y][x] = '.';
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (inRange(nx, ny)) {
						map[ny][nx] = '.';
					}
				}
			}
		}
		else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (map[i][j] == 'O') {
						q.push(make_pair(j, i));
					}
					else
						map[i][j] = 'O';
				}
			}
		}
		time++;
	}
	print(map);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> n;
	vector<vector<char>> map(r, vector<char>(c));
	queue<pair<int, int>> q;
	for(int i=0; i<r; i++)
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if(map[i][j] == 'O')
				q.push(make_pair(j, i));
		}
	bfs(map, q);
	return 0;
}