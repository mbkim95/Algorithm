#include <iostream>
#include <algorithm>
using namespace std;

int ans = 100;
int map[10][10];
int paper[] = { 5, 5, 5, 5, 5 };

bool inRange(int x, int y) {
	return (0 <= x && x < 10) && (0 <= y && y < 10);
}

bool check(int x, int y, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[size-1] == 0 || !inRange(j, i) || map[i][j] == 0)
				return false;
		}
	}
	return true;
}

void changeField(int x, int y, int size, int value) {
	if (value == 1) {
		paper[size - 1]++;
	}
	else {
		paper[size - 1]--;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[y + i][x + j] = value;
		}
	}
}

bool isEmpty() {
	for (int i = 0; i < 5; i++) {
		if (paper[i] != 0)
			return false;
	}
	return true;
}

void solve(int idx, int cnt) {
	if (idx == 100) {
		ans = min(ans, cnt);
		return;
	}

	int x = idx % 10;
	int y = idx / 10;

	if (ans <= cnt)
		return;

	if (map[y][x]) {
		for (int i = 5; i >= 1; i--) {
			if (check(x, y, i)) {
				changeField(x, y, i, 0);
				solve(idx + 1, cnt + 1);
				changeField(x, y, i, 1);
			}
		}
	}
	else
		solve(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}

	solve(0, 0);
	ans = (ans == 100 ? -1 : ans);
	cout << ans << '\n';
	return 0;
}