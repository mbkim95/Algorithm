#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int ans;
char map[5][6];
bool team[5][5];
bool chk[25];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };


void can_make_group() {
	memset(team, false, sizeof(team));
	vector<vector<bool>> visited(5, vector<bool>(5, false));
	int s_cnt = 0;
	bool first = true;
	queue<pair<int, int>> q;
	// 7개의 숫자를 좌표로 변환하여 배열에 표시
	for (int i = 0; i < 25; i++) {
		if (!chk[i]) continue;
		int x = i % 5;
		int y = i / 5;
		team[y][x] = true;
		if (map[y][x] == 'S') {
			s_cnt++;
			if (first) {
				q.push({ x, y });
				visited[y][x] = true;
				first = false;
			}
		}
	}
	// 이다솜파의 숫자가 4보다 작으면 안되므로 종료시킨다
	if (s_cnt < 4) return;

	int cnt = 1;

	// 7공주가 모두 연결되어있는지 확인
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (cnt == 7) {
			ans++;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
			if (!visited[ny][nx] && team[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
}

// 7개의 숫자를 추출
void dfs(int idx, int cnt) {
	if (cnt == 7) {
		can_make_group();
		return;
	}

	for (int i = idx+1; i < 25; i++) {
		if (!chk[i]) {
			chk[i] = true;
			dfs(i, cnt + 1);
			chk[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];

	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}