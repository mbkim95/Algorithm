#include <iostream>
#include <vector>
using namespace std;

int n, l;
vector<vector<int>> map;

int countRow(int row) {
	int len = 0;
	int tmp = map[row][0];
	for (int i = 0; i < n; i++) {
		if (tmp == map[row][i])			// 이전 높이 == 현재 높이
			len++;
		else {
			if (tmp + 1 == map[row][i]) {		// 이전 높이 + 1 == 현재 높이
				if (len < l)					// 이전 높이의 값이 l보다 크면 가능
					return 0;
				len = 1;
			}
			else if (tmp - 1 == map[row][i]) {		// 이전 높이 - 1 == 현재 높이
				int j = 0;
				for (j = 0; j < l; j++) {
					if (i + j >= n || map[row][i] != map[row][i + j])	return 0;
				}
				i += j - 1;
				len = 0;
			}
			else
				return 0;
			tmp = map[row][i];
		}
	}
	return 1;
}

int countColumn (int col) {
	int len = 0;
	int tmp = map[0][col];
	for (int i = 0; i < n; i++) {
		if (tmp == map[i][col])			// 이전 높이 == 현재 높이
			len++;
		else {
			if (tmp + 1 == map[i][col]) {		// 이전 높이 + 1 == 현재 높이
				if (len < l)					// 이전 높이의 값이 l보다 크면 가능
					return 0;
				len = 1;
			}
			else if (tmp - 1 == map[i][col]) {		// 이전 높이 - 1 == 현재 높이
				int j = 0;
				for (j = 0; j < l; j++) {
					if (i + j >= n || map[i][col] != map[i + j][col])	return 0;
				}
				i += j - 1;
				len = 0;
			}
			else
				return 0;
			tmp = map[i][col];
		}
	}
	return 1;
}

void solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += countRow(i);
		ans += countColumn(i);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l;
	map = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	solve();
	return 0;
}