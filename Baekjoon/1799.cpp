#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans1, ans2;
vector<vector<int>> board;
vector<bool> inc1, dec1, inc2, dec2;
vector<pair<int, int>> pos1, pos2;

void dfs1(int idx, int cnt) {
	if (idx >= pos1.size()) {
		ans1 = max(ans1, cnt);
		return;
	}

	int x = pos1[idx].first;
	int y = pos1[idx].second;
	if (!inc1[x + y] && !dec1[(y - x) + n - 1]) {
		inc1[x + y] = dec1[(y - x) + n - 1] = true;
		dfs1(idx + 1, cnt + 1);
		inc1[x + y] = dec1[(y - x) + n - 1] = false;
	}
	dfs1(idx + 1, cnt);
}

void dfs2(int idx, int cnt) {
	if (idx >= pos2.size()) {
		ans2 = max(ans2, cnt);
		return;
	}

	int x = pos2[idx].first;
	int y = pos2[idx].second;
	if (!inc2[x + y] && !dec2[(y - x) + n - 1]) {
		inc2[x + y] = dec2[(y - x) + n - 1] = true;
		dfs2(idx + 1, cnt + 1);
		inc2[x + y] = dec2[(y - x) + n - 1] = false;
	}
	dfs2(idx + 1, cnt);
}

void dfsAll() {
	int x, y;
	if (pos1.size() != 0) {
		x = pos1[0].first;
		y = pos1[0].second;
		inc1[x + y] = dec1[(y - x) + n - 1] = true;
		dfs1(1, 1);
		inc1[x + y] = dec1[(y - x) + n - 1] = false;
		dfs1(0, 0);
	}

	if (pos2.size() != 0) {
		x = pos2[0].first;
		y = pos2[0].second;
		inc2[x + y] = dec2[(y - x) + n - 1] = true;
		dfs2(1, 1);
		inc2[x + y] = dec2[(y - x) + n - 1] = false;
		dfs2(0, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	board = vector<vector<int>>(n, vector<int>(n));
	inc1 = vector<bool>(2 * n, false);
	dec1 = vector<bool>(2 * n, false);
	inc2 = vector<bool>(2 * n, false);
	dec2 = vector<bool>(2 * n, false);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j])
				if ((i + j) % 2) {
					pos2.push_back(make_pair(j, i));
				}
				else
					pos1.push_back(make_pair(j, i));
		}
 
	dfsAll();
	cout << ans1 + ans2 << '\n';
	return 0;
}