#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool chkNumber(int number, vector<bool>& num) {
	if (number == 0 && !num[0])
		return false;
	while (number > 0) {
		int rest = number % 10;
		number /= 10;
		if (!num[rest])	return false;
	}
	return true;
}

int bfs(int n, vector<bool>& num) {
	vector<bool> chk(1000000, false);
	queue<pair<int, int>> q;
	chk[n] = true;
	q.push(make_pair(n, 0));
	int ret = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		if (now.first == 100) {
			ret += now.second;
			break;
		}
		if (chkNumber(now.first, num)) {
			ret += to_string(now.first).length();
			ret += now.second;
			break;
		}
		if (0 <= now.first - 1 && !chk[now.first - 1]) {
			chk[now.first - 1] = true;
			q.push(make_pair(now.first - 1, now.second + 1));
		}
		if (now.first + 1 <= 999999 && !chk[now.first + 1]) {
			chk[now.first + 1] = true;
			q.push(make_pair(now.first + 1, now.second + 1));
		}
	}
	return ret;
}

int solve(int n, vector<bool>& num) {
	int ans = 987654321;
	if (n == 100)
		ans = 0;
	else {
		int cand = bfs(n, num);
		if (n > 100)
			ans = min(cand, n - 100);
		else
			ans = min(cand, 100 - n);
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	vector<bool> num(10, true);
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		num[tmp] = false;
	}
	cout << solve(n, num) << '\n';
	return 0;
}