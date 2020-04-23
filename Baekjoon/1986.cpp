#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[1001][1001];
vector<pair<int, int>> q, k;

void move_queen(int x, int y) {
	int nx = x;
	while (nx <= m) {
		nx++;
		if (nx > m || board[y][nx] == 1) break;
		board[y][nx] = 2;
	}
	nx = x;
	while (nx >= 1) {
		nx--;
		if (nx < 1 || board[y][nx] == 1) break;
		board[y][nx] = 2;
	}
	int ny = y;
	while (ny <= n) {
		ny++;
		if (ny > n || board[ny][x] == 1) break;
		board[ny][x] = 2;
	}
	ny = y;
	while (ny >= 1) {
		ny--;
		if (ny < 1 || board[ny][x] == 1) break;
		board[ny][x] = 2;
	}

	nx = x;
	ny = y;
	while (nx <= m && ny >= 1) {
		nx++;
		ny--;
		if (!(nx <= m && ny >= 1) || board[ny][nx] == 1) break;
		board[ny][nx] = 2;
	}
	nx = x;
	ny = y;
	while (nx >= 1 && ny <= n) {
		nx--;
		ny++;
		if (!(nx >= 1 && ny <= n) || board[ny][nx] == 1) break;
		board[ny][nx] = 2;
	}
	nx = x;
	ny = y;
	while (nx <= m && ny <= n) {
		nx++;
		ny++;
		if (!(nx <= m && ny <= n) || board[ny][nx] == 1) break;
		board[ny][nx] = 2;
	}
	nx = x;
	ny = y;
	while (nx >= 1 && ny >= 1) {
		nx--;
		ny--;
		if (!(nx >= 1 && ny >= 1) || board[ny][nx] == 1) break;
		board[ny][nx] = 2;
	}
}

void move_knight(int x, int y) {
	const int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 }, dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
		if (board[ny][nx] == 0) board[ny][nx] = 2;
	}
}

int main() {

	cin >> n >> m;
	int num;
	cin >> num;
	while (num--) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
		q.push_back({ x, y });
	}

	cin >> num;
	while (num--) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
		k.push_back({ x, y });
	}

	cin >> num;
	while (num--) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
	}

	for (auto h : q)
		move_queen(h.first, h.second);
	for (auto h : k)
		move_knight(h.first, h.second);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (board[i][j] == 0) ans++;
	cout << ans << '\n';
	return 0;
}