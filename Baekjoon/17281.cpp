#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int hit[51][10];
bool base[4], chk[10];
vector<int> order;

int simulation() {
	int out = 0, hitter = 1, inning = 1, score = 0;
	while (true) {
		if (inning == n + 1) break;
		int info = hit[inning][order[hitter-1]];
		if (info == 1) {
			for (int i = 3; i >= 1; i--)
				if (base[i]) {
					if (i == 3) {
						base[i] = false;
						score++;
					}
					else {
						base[i + 1] = true;
						base[i] = false;
					}
				}
			base[1] = true;
		}
		else if (info == 2) {
			for (int i = 3; i >= 1; i--) {
				if (base[i]) {
					if (i == 1) {
						base[i + 2] = true;
						base[i] = false;
					}
					else {
						base[i] = false;
						score++;
					}
				}
			}
			base[2] = true;
		}
		else if (info == 3) {
			for (int i = 3; i >= 1; i--) {
				if (base[i]) {
					base[i] = false;
					score++;
				}
			}
			base[3] = true;
		}
		else if (info == 4) {
			for (int i = 1; i <= 3; i++) {
				if (base[i]) score++;
				base[i] = false;
			}
			score++;
		}
		else {
			out++;
			if (out == 3) {
				inning++;
				out = 0;
				for (int i = 1; i <= 3; i++) base[i] = false;
			}
		}
		hitter++;
		if (hitter == 10) hitter = 1;
	}
	return score;
}

void dfs(int cnt) {
	if (cnt == 9) {
		ans = max(ans, simulation());
		return;
	}

	if (cnt == 3) {
		chk[1] = true;
		order.push_back(1);
		dfs(cnt + 1);
		order.pop_back();
		chk[1] = false;
	}

	for (int i = 1; i <= 9; i++) {
		if (!chk[i] && i != 1) {
			chk[i] = true;
			order.push_back(i);
			dfs(cnt + 1);
			order.pop_back();
			chk[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 9; j++)
			cin >> hit[i][j];
	for (int i = 1; i <= 9; i++) {
		if (i == 1) continue;
		chk[i] = true;
		order.push_back(i);
		dfs(1);
		order.pop_back();
		chk[i] = false;
	}
	cout << ans << '\n';
	return 0;
}