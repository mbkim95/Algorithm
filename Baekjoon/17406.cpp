#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
vector<vector<int>> arr;
vector<pair<pair<int, int>, int>> ops;
vector<int> order, chk;
int ans = 987654321;

void rotate(int sx, int sy, int ex, int ey) {
	if (sx == ex && sy == ey)
		return;

	deque<int> dq;
	for (int i = sx; i <= ex; i++)
		dq.push_back(arr[sy][i]);
	for (int i = sy + 1; i <= ey; i++)
		dq.push_back(arr[i][ex]);
	for (int i = ex - 1; i >= sx; i--)
		dq.push_back(arr[ey][i]);
	for (int i = ey - 1; i >= sy + 1; i--)
		dq.push_back(arr[i][sx]);
	dq.push_front(dq.back());
	dq.pop_back();

	for (int i = sx; i <= ex; i++) {
		arr[sy][i] = dq.front();
		dq.pop_front();
	}
	for (int i = sy + 1; i <= ey; i++) {
		arr[i][ex] = dq.front();
		dq.pop_front();
	}
	for (int i = ex - 1; i >= sx; i--) {
		arr[ey][i] = dq.front();
		dq.pop_front();
	}
	for (int i = ey - 1; i >= sy + 1; i--) {
		arr[i][sx] = dq.front();
		dq.pop_front();
	}

	rotate(sx + 1, sy + 1, ex - 1, ey - 1);
}

void rotateArr() {
	for (int i = 0; i < order.size(); i++) {
		int r = ops[order[i]].first.first;
		int s = ops[order[i]].first.second;
		int c = ops[order[i]].second;
		rotate(s - c, r - c, s + c, r + c);
	}
}

void dfs(int cnt) {
	if (cnt == ops.size()) {
		vector<vector<int>> bkup = arr;
		rotateArr();
		int tmp = 987654321;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++)
				sum += arr[i][j];
			tmp = min(tmp, sum);
		}		
		ans = min(ans, tmp);
		arr = bkup;
		return;
	}

	for (int i = 0; i < ops.size(); i++) {
		if (!chk[i]) {
			chk[i] = 1;
			order.push_back(i);
			dfs(cnt + 1);
			order.pop_back();
			chk[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	arr = vector<vector<int>>(n + 1, vector<int>(m + 1));
	chk = vector<int>(k, 0);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> arr[i][j];
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		ops.push_back({ {r, c}, s });
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}