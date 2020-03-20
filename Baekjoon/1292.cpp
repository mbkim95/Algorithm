#include <iostream>
using namespace std;

int num[1001];

void precalc() {
	int idx = 1;
	int cnt = 1;
	while (idx <= 1000) {
		for (int i = 0; i < cnt; i++) {
			num[idx] = cnt;
			idx++;

			if (idx == 1001) return;
		}
		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	precalc();
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; i++) 
		ans += num[i];
	cout << ans << '\n';
	return 0;
}