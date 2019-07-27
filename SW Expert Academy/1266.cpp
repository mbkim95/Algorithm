#include <iostream>
#include <queue>
using namespace std;

int sx, sy, ex, ey;
int map[16][16];
const int dx[] = { 0, -1, 0, 1 }, dy[] = { -1, 0, 1, 0 };

bool inRange(int x, int y) {
	return (0 <= x && x < 16) && (0 <= y && y < 16);
}

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		if (map[ey][ex] == 5)
			return 1;
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = here.first + dx[i];
			int ny = here.second + dy[i];
			if (inRange(nx, ny) && map[ny][nx] == 0) {
				q.push(make_pair(nx, ny));
				map[ny][nx] = 5;
			}
		}

	}
	return 0;
}
 
int main() {
	for (int t = 1; t <= 10; t++) {
		int tc;
		scanf("%d", &tc);

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					map[i][j] = 5;
					sx = j;
					sy = i;
				}
				else if (map[i][j] == 3){
					map[i][j] = 0;
					ex = j;
					ey = i;
				}	
			}
		}
		printf("#%d %d\n", t, bfs());
	}
	return 0;
}