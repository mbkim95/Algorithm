#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int r, c, t, ans;
vector<vector<int>> map;
vector<pair<int, int>> dust;
int h;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < c) && (0 <= y && y < r);
}

void print() {
	cout << "PRINT\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void wind() {
	vector<vector<int>> tmp(r, vector<int>(c, 0));
	tmp[h - 1][0] = tmp[h][0] = -1;

	for (int i = 0; i < dust.size(); i++){
		int x = dust[i].first, y = dust[i].second;
		if (y <= h - 1) {
			if (x == 0 && y == h - 2)
				continue;
			else if (x == 0 && 0 <= y && y < h - 2)
				tmp[y + 1][x] = map[y][x];
			else if (x == c - 1 && 1 <= y && y <= h - 1) {
				tmp[y - 1][x] = map[y][x];
			}
			else if (y == 0) {
				tmp[y][x - 1] = map[y][x];
			}
			else if (y == h - 1)
				tmp[y][x + 1] = map[y][x];
			else
				tmp[y][x] = map[y][x];
		}
		else if (y >= h) {
			if (x == 0 && y == h + 1)
				continue;
			if (x == 0 && h + 2 <= y && y <= r)
				tmp[y - 1][x] = map[y][x];
			else if (x == c - 1 && h <= y && y <= r - 2) {
				tmp[y + 1][x] = map[y][x];
			}
			else if (y == h) {
				tmp[y][x + 1] = map[y][x];
			}
			else if (y == r - 1)
				tmp[y][x - 1] = map[y][x];
			else
				tmp[y][x] = map[y][x];
		}
	}
	map = tmp;
	dust.clear();
	ans = 0;
	for(int i=0; i<r; i++)
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				dust.push_back(make_pair(j, i));
				ans += map[i][j];
			}
		}
}

void spreadDust() {
	vector<vector<int>> tmp(r, vector<int>(c, 0));
	for (int i = 0; i < dust.size(); i++) {
		int x = dust[i].first, y = dust[i].second;
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (inRange(nx, ny) && map[ny][nx] != -1) {
				cnt++;
				tmp[ny][nx] += (map[y][x] / 5);
			}
		}
		tmp[y][x] += (map[y][x] - (cnt * (map[y][x]/5)));
	}
	dust.clear();
	map = tmp;
	ans = 0;
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			if (map[i][j] > 0) {
				dust.push_back(make_pair(j, i));
				ans += map[i][j];
			}
}

void solve() {
	for (int i = 0; i < t; i++) {
		spreadDust();
		wind();
	}
	cout << ans << '\n';
}

int main() {
	cin >> r >> c >> t;
	map = vector<vector<int>>(r, vector<int>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				dust.push_back(make_pair(j, i));
				ans += map[i][j];
			}
			if (map[i][j] == -1) h = i;
		}
	solve();
	return 0;
}