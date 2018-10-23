#include <iostream>
using namespace std;

int n, s, cnt;
int num[20];
bool chk[20];

void solve(int idx, int sum) {	
	if (idx == n) {
		if (sum == s)
			cnt++;
		return;
	}

	solve(idx + 1, sum + num[idx]);
	solve(idx + 1, sum);

}

int main() {
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	solve(0, 0);

	// 공집합인 경우 제외
	if (s == 0)
		cnt--;

	cout << cnt << '\n';

	return 0;
}