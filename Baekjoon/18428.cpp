#include <iostream>
#include <vector>
using namespace std;

int n, answer;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 }; \
vector<pair<int, int>> cand, teachers;
char board[6][6];

int check() {
	for (pair<int, int> t : teachers) {
		for (int i = 0; i < 4; i++) {
			int nx = t.first;
			int ny = t.second;
			while (true) {
				nx += dx[i];
				ny += dy[i];
				if (nx <0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[ny][nx] == 'O') break;
				if (board[ny][nx] == 'S') return 0;
			}
		}
	}
	return 1;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		answer += check();
		return;
	}

	for (int i = idx + 1; i < cand.size(); i++) {
		int x = cand[i].first;
		int y = cand[i].second;
		board[y][x] = 'O';
		dfs(i, cnt + 1);
		board[y][x] = 'X';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'X') cand.push_back({ j, i });
			else if (board[i][j] == 'T') teachers.push_back({ j, i });
		}
	dfs(-1, 0);
	if (answer == 0) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}