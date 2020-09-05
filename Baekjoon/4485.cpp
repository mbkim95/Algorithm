#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

struct Link {
	int x, y, dir;
};

int map[125][125];
int chk[125][125][4];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

void init(int size) {
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
			for (int k = 0; k < 4; k++)
				chk[i][j][k] = MAX;		
}

int bfs(int size) {
	init(size);
	queue<Link> q;
	for (int i = 0; i < 4; i++) {
		chk[0][0][i] = map[0][0];
		q.push({ 0, 0, i });
	}

	while (!q.empty()) {
		Link cur = q.front();
		q.pop();

		int x = cur.x;
		int y = cur.y;
		int dir = cur.dir;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > size - 1 || ny < 0 || ny > size - 1) continue;
			if (chk[ny][nx][i] > chk[y][x][dir] + map[ny][nx]) {
				chk[ny][nx][i] = chk[y][x][dir] + map[ny][nx];
				q.push({ nx, ny, i });
			}
		}
	}

	int ret = MAX;
	for (int i = 0; i < 4; i++) ret = min(ret, chk[size - 1][size - 1][i]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (true) {
		int size;
		cin >> size;
		if (size == 0) break;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> map[i][j];
		cout << "Problem " << t++ << ": " << bfs(size) << '\n';
	}
	return 0;
}