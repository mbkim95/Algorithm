#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, t, ans;
vector<vector<int>> c;

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
}

// 원판 회전
void spin(int idx, int x, int dir, int k) {
	if (idx - 1 >= n) return;
	int tmp = k;
	deque<int> q;
	for (int i = 0; i < m; i++)
		q.push_back(c[idx - 1][i]);

	while (tmp--) {
		if (dir == 0) {
			q.push_front(q.back());
			q.pop_back();
		}
		else {
			q.push_back(q.front());
			q.pop_front();
		}
	}

	for (int i = 0; i < m; i++) {
		c[idx - 1][i] = q.front();
		q.pop_front();
	}
	spin(idx + x, x, dir, k);
}

// 인접한 숫자 제거
void remove() {
	vector<vector<bool>> adj(n, vector<bool>(m, false));
	ans = 0;
	int chk = 0;
	int non_zero = 0;

	// 같은 원판에 인접한 숫자들 검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j++) {
			if (c[i][j] == 0) continue;
			if (c[i][j] == c[i][j + 1]) {
				adj[i][j] = true;
				adj[i][j + 1] = true;
			}
		}
		if (c[i][m-1] == 0) continue;
		if (c[i][0] == c[i][m - 1]) {
			adj[i][0] = true;
			adj[i][m - 1] = true;
		}
	}

	// 같은 위치의 인접한 숫자 검사
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 0) continue;
			if (c[i][j] == c[i + 1][j]) {
				adj[i][j] = true;
				adj[i + 1][j] = true;
			}
		}
	}

	// 인접한 숫자들 제거
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (adj[i][j]) {
				c[i][j] = 0;
				chk++;
			}
			if (c[i][j] != 0) non_zero++;
			ans += c[i][j];
		}
	}

	// 평균을 정확하게 하기 위해서 double 자료형 사용
	double tmp = ans;
	// 제거할 숫자가 없는 경우 평균값을 구해서 증가시킴
	if (chk == 0) {
		ans = 0;
		tmp /= non_zero;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == 0) continue;
				if (c[i][j] > tmp) c[i][j]--;
				else if (c[i][j] < tmp) c[i][j]++;
				ans += c[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	c = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];

	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		spin(x, x, d, k);
		remove();
	}
	cout << ans << '\n';
	return 0;
}