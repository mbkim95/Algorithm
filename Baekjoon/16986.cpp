#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int a[10][10];
int jw[10], kh[20], mh[20];

bool simulation() {	
	int jw_idx = 0, kh_idx = 0, mh_idx = 0;
	int jw_win = 0, kh_win = 0, mh_win = 0;
	int rest = 2;

	while (true) {
		if (jw_win == k) return true;
		if (jw_idx == n || kh_win == k || mh_win == k) return false;
		if (rest == 2) {
			int v = a[jw[jw_idx++]][kh[kh_idx++]];
			if (v == 2) {
				jw_win++;
				rest = 1;
			}
			else {
				kh_win++;
				rest = 0;
			}
		}
		else if (rest == 1) {
			int v = a[jw[jw_idx++]][mh[mh_idx++]];
			if (v == 2) {
				jw_win++;
				rest = 2;
			}
			else {
				mh_win++;
				rest = 0;
			}
		}
		else {
			int v = a[kh[kh_idx++]][mh[mh_idx++]];
			if (v == 2) {
				kh_win++;
				rest = 2;
			}
			else {
				mh_win++;
				rest = 1;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	for (int i = 0; i < 20; i++) cin >> kh[i];
	for (int i = 0; i < 20; i++) cin >> mh[i];
	for (int i = 0; i < n; i++) jw[i] = i + 1;

	bool find = false;
	do {
		if (simulation()) {
			find = true;
			cout << "1\n";
			break;
		}
	} while (next_permutation(jw, jw+n));
	if (!find) cout << "0\n";
	return 0;
}