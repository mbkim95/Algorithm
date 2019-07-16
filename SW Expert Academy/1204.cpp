#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int score[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int num, tmp, ans = 0, ret = 0;
		cin >> num;

		memset(score, 0, sizeof(score));
		for (int i = 0; i < 1000; i++) {
			cin >> tmp;
			score[tmp]++;
		}
		for (int i = 0; i < 100; i++) {
			if (ans <= score[i]) {
				ans = score[i];
				ret = i;
			}
		}
		cout << "#" << c << ' ' << ret << '\n';
	}
	return 0;
}