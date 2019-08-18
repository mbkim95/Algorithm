#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int garo, sero;

int getSize(vector<vector<int>>& a) {
	garo = sero = 0;
	for (int j = 1; j <= 100; j++) {
		int cnt = 0;
		for (int i = 1; i <= 100; i++) {
			if (a[i][j] != 0) 
				cnt++;
		}
		sero = max(sero, cnt);
	}

	for (int i = 1; i <= 100; i++) {
		int cnt = 0;
		for (int j = 1; j <= 100; j++) {
			if (a[i][j] != 0) 
				cnt++;
		}
		garo = max(garo, cnt);
	}
	if (garo <= sero)
		return 1;
	else
		return 0;
}

void C(vector<vector<int>>& a) {
	for (int j = 1; j <= 100; j++) {
		vector<int> cnt(101, 0);
		vector<pair<int, int>> tmp;
		for (int i = 1; i <= 100; i++) {
			if (a[i][j] != 0)
				cnt[a[i][j]]++;
		}
		int count = 0;
		for (int i = 1; i <= 100; i++)
			if (cnt[i] != 0) {
				count++;
				tmp.push_back(make_pair(cnt[i], i));
			}
		sort(tmp.begin(), tmp.end());
		int idx = 0;
		for (int i = 1; i <= 100; i += 2) {
			if (2 * count > i) {
				a[i][j] = tmp[idx].second;
				a[i + 1][j] = tmp[idx].first;
				idx++;
			}
			else
				a[i][j] = a[i + 1][j] = 0;
		}
	}
}

void R(vector<vector<int>>& a) {
	for (int i = 1; i <= 100; i++) {
		vector<int> cnt(101, 0);
		vector<pair<int, int>> tmp;
		for (int j = 1; j <= 100; j++) {
			if (a[i][j] != 0)
				cnt[a[i][j]]++;
		}
		int count = 0;
		for (int j = 1; j <= 100; j++)
			if (cnt[j] != 0) {
				count++;
				tmp.push_back(make_pair(cnt[j], j));
			}
		sort(tmp.begin(), tmp.end());
		int idx = 0;
		for (int j = 1; j <= 100; j += 2) {
			if (2 * count > j) {
				a[i][j] = tmp[idx].second;
				a[i][j + 1] = tmp[idx].first;
				idx++;
			}
			else
				a[i][j] = a[i][j + 1] = 0;
		}
	}
}

int solve(vector<vector<int>>& a) {
	int time = 0;
	while (true) {
		if (a[r][c] == k)
			break;

		if (time > 100)
			return -1;
		int rc = getSize(a);
		if (rc == 1) { // R연산
			R(a);
		}
		else {			// C 연산
			C(a);
		}
		getSize(a);
		time++;
	}
	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> k;
	vector<vector<int>>a(101, vector<int>(101, 0));
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	cout << solve(a) << '\n';
	return 0;
}