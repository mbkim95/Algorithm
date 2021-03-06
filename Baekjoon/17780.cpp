#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Knight {
	int x, y, dir;
	bool canMove;
}k[11];

int N, K;
int map[13][13];
vector<int> list[13][13];
const int dx[] = { 0, 1, -1, 0, 0 }, dy[] = { 0, 0, 0, -1, 1 }, back[] = { 0, 2, 1, 4, 3 };

int moveKnight(int idx) {
	int nx = k[idx].x + dx[k[idx].dir];
	int ny = k[idx].y + dy[k[idx].dir];

	if (nx < 1 || nx > N || ny < 1 || ny > N || map[ny][nx] == 2) {
		k[idx].dir = back[k[idx].dir];
		nx = k[idx].x + dx[k[idx].dir];
		ny = k[idx].y + dy[k[idx].dir];

		if (nx < 1 || nx > N || ny < 1 || ny > N || map[ny][nx] == 2) return list[k[idx].y][k[idx].x].size();
	}

	vector<int>& cur = list[k[idx].y][k[idx].x];
	vector<int>& next = list[ny][nx];

	if (map[ny][nx] == 1) reverse(cur.begin(), cur.end());

	for (auto it = cur.begin(); it != cur.end(); it++) {
		k[*it].x = nx;
		k[*it].y = ny;
		k[*it].canMove = false;
		next.push_back(*it);
	}
	if (next.size() == cur.size()) k[next[0]].canMove = true;
	cur.clear();
	return next.size();
}

int simulation() {
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= K; j++) {
			if (k[j].canMove == false) continue;
			int cnt = moveKnight(j);
			if (cnt >= 4) return i;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= K; i++) {
		cin >> k[i].y >> k[i].x >> k[i].dir;
		k[i].canMove = true;
		list[k[i].y][k[i].x].push_back(i);
	}
	cout << simulation() << '\n';
	return 0;
}