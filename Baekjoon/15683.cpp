#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> cctv;
vector<int> direction;

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

void cctv1(vector<vector<int>>& map, int idx) {
	const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int dir = direction[idx];
	
	while (inRange(x, y) && (map[y][x] != 6)) {
		if (!map[y][x])
			map[y][x] = 9;
		x += dx[dir];
		y += dy[dir];
	}
}

void cctv2(vector<vector<int>>& map, int idx) {
	const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int dir = direction[idx];

	if (dir == 1 || dir == 3) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[0];
			y += dy[0];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[2];
			y += dy[2];
		}
	}
	else if (dir == 2 || dir == 4) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[1];
			y += dy[1];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[3];
			y += dy[3];
		}
	}
}

void cctv3(vector<vector<int>>& map, int idx) {
	const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int dir = direction[idx];

	if (dir == 1) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[0];
			y += dy[0];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[1];
			y += dy[1];
		}
	}
	else if (dir == 2) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[1];
			y += dy[1];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[2];
			y += dy[2];
		}
	}
	else if (dir == 3) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[2];
			y += dy[2];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[3];
			y += dy[3];
		}
	}
	else {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[3];
			y += dy[3];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[0];
			y += dy[0];
		}
	}
}

void cctv4(vector<vector<int>>& map, int idx) {
	const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int dir = direction[idx];

	if (dir == 1) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[0];
			y += dy[0];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[1];
			y += dy[1];
		}

		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[2];
			y += dy[2];
		}
	}
	else if (dir == 2) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[1];
			y += dy[1];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[2];
			y += dy[2];
		}

		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[3];
			y += dy[3];
		}
	}
	else if (dir == 3) {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[2];
			y += dy[2];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[3];
			y += dy[3];
		}

		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[0];
			y += dy[0];
		}
	}
	else {
		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[3];
			y += dy[3];
		}
		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[0];
			y += dy[0];
		}

		x = cctv[idx].first;
		y = cctv[idx].second;

		while (inRange(x, y) && (map[y][x] != 6)) {
			if (!map[y][x])
				map[y][x] = 9;
			x += dx[1];
			y += dy[1];
		}
	}
}

void cctv5(vector<vector<int>>& map, int idx) {
	const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int dir = direction[idx];

	while (inRange(x, y) && (map[y][x] != 6)) {
		if (!map[y][x])
			map[y][x] = 9;
		x += dx[0];
		y += dy[0];
	}

	x = cctv[idx].first;
	y = cctv[idx].second;

	while (inRange(x, y) && (map[y][x] != 6)) {
		if (!map[y][x])
			map[y][x] = 9;
		x += dx[1];
		y += dy[1];
	}

	x = cctv[idx].first;
	y = cctv[idx].second;

	while (inRange(x, y) && (map[y][x] != 6)) {
		if (!map[y][x])
			map[y][x] = 9;
		x += dx[2];
		y += dy[2];
	}

	x = cctv[idx].first;
	y = cctv[idx].second;

	while (inRange(x, y) && (map[y][x] != 6)) {
		if (!map[y][x])
			map[y][x] = 9;
		x += dx[3];
		y += dy[3];
	}
}

int getAnswer(vector<vector<int>>& map) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				ret++;
		}
	}
	return ret;
}

void dfs(int idx) {
	if (idx == cctv.size()) {
		vector<vector<int>> tmp = map;
		for (int i = 0; i < idx; i++) {
			int x = cctv[i].first;
			int y = cctv[i].second;
			int id = map[y][x];
			if (id == 1)
				cctv1(tmp, i);
			else if (id == 2) 
				cctv2(tmp, i);
			else if(id ==3)
				cctv3(tmp, i);
			else if(id ==4)
				cctv4(tmp, i);
			else
				cctv5(tmp, i);
		}
		ans = min(ans, getAnswer(tmp));
		return;
	}

	for (int i = 0; i < 4; i++) {
		direction[idx] = i;
		dfs(idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				cctv.push_back(make_pair(j, i));
		}
	}
	direction = vector<int>(cctv.size());
	ans = 987654321;
	dfs(0);
	cout << ans << '\n';
	return 0;
}