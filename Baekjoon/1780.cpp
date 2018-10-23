#include <iostream>
using namespace std;

int p[2188][2188];
int ans[3], n;

bool check(int y, int x, int size) {
	int tmp = p[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tmp != p[i][j])
				return false;
		}
	}
	return true;
}

void solve(int x, int y, int size) {
	if (check(y, x, size)) {
		ans[p[y][x] + 1]++;
		return;
	}
	else {
		int s = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(x + s * i, y + s * j, s);
			}
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> p[i][j];
	solve(1, 1, n);
	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << endl;
}