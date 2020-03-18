#include <iostream>
#include <vector>
using namespace std;

int d[10];
int m[33];
int score[33];
int cp[33];
int h[4];
int ans;
bool chk[33];

void precalc() {
	for (int i = 0; i < 21; i++) {
		m[i] = i + 1;
		score[i] = i * 2;
	}
	score[21] = 0;
	for (int i = 0; i < 3; i++)
		score[22 + i] = 13 + 3 * i;
	for (int i = 0; i < 3; i++)
		score[30 + i] = 28 - i;
	for (int i = 0; i < 2; i++)
		score[28 + i] = 22 + 2 * i;
	for (int i = 0; i < 3; i++)
		score[25 + i] = 25 + 5 * i;	
	for (int i = 22; i <= 26; i++)
		m[i] = i + 1;
	m[21] = 21;
	m[27] = 20;
	m[28] = 29;
	m[29] = 25;
	m[30] = 31;
	m[31] = 32;
	m[32] = 25;
	cp[5] = 22;
	cp[10] = 28;
	cp[15] = 30;
}

void dfs(int cnt, int sum) {
	if (cnt == 10) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int prev = h[i];
		int now = prev;
		int move = d[cnt];

		if (cp[now] > 0) {
			now = cp[now];
			move--;
		}

		while (move--) {
			now = m[now];
		}

		if (now != 21 && chk[now]) continue;

		chk[prev] = false;
		chk[now] = true;
		h[i] = now;
		dfs(cnt + 1, sum + score[now]);
		h[i] = prev;
		chk[now] = false;
		chk[prev] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	precalc();
	for (int i = 0; i < 10; i++)
		cin >> d[i];

	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}