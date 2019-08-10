#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, y, k;
const int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
int dice[] = { 0, 0, 0, 0, 0, 0 };
// À­¸é, ¾Õ¸é, ¹Ø¸é, µÞ¸é, ¿ÞÂÊ¸é, ¿À¸¥ÂÊ¸é
// 0	1		2		3	4		5
vector<vector<int>> map;

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

void rolling(int dir) {
	int tmp[] = { dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] };
	if (dir == 1) {		// µ¿ÂÊ
		dice[0] = tmp[4];
		dice[1] = tmp[1];
		dice[2] = tmp[5];
		dice[3] = tmp[3];
		dice[4] = tmp[2];
		dice[5] = tmp[0];
		// ¿ÞÂÊ¸é, ¾Õ¸é, ¿À¸¥ÂÊ¸é, µÞ¸é, ¹Ø¸é, À­¸é
	}
	else if (dir == 2) {	// ¼­ÂÊ
		dice[0] = tmp[5];
		dice[1] = tmp[1];
		dice[2] = tmp[4];
		dice[3] = tmp[3];
		dice[4] = tmp[0];
		dice[5] = tmp[2];
		// ¿À¸¥ÂÊ¸é, ¾Õ¸é, ¿ÞÂÊ¸é, µÞ¸é, À­¸é, ¹Ø¸é
	}
	else if (dir == 3) {	// ºÏÂÊ
		dice[0] = tmp[1];
		dice[1] = tmp[2];
		dice[2] = tmp[3];
		dice[3] = tmp[0];
		dice[4] = tmp[4];
		dice[5] = tmp[5];
		// ¾Õ¸é, ¹Ø¸é, µÞ¸é, À­¸é, ¿ÞÂÊ¸é, ¿À¸¥ÂÊ¸é
	}
	else {		//³²ÂÊ
		dice[0] = tmp[3];
		dice[1] = tmp[0];
		dice[2] = tmp[1];
		dice[3] = tmp[2];
		dice[4] = tmp[4];
		dice[5] = tmp[5];
		// µÞ¸é, À­¸é, ¾Õ¸é, ¹Ø¸é, ¿ÞÂÊ¸é, ¿À¸¥ÂÊ¸é
	}
}

void solve() {
	int hx = x, hy = y;
	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;
		if (inRange(hx + dx[dir - 1], hy + dy[dir - 1])) {
			hx += dx[dir - 1];
			hy += dy[dir - 1];
			rolling(dir);
			if (map[hx][hy] == 0) {
				map[hx][hy] = dice[2];
			}
			else {
				dice[2] = map[hx][hy];
				map[hx][hy] = 0;
			}
			cout << dice[0] << '\n';
		}
	}
}

int main() {
	cin >> n >> m >> x >> y >> k;
	map = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	solve();
	return 0;
}