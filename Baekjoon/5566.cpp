#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> board(n + 1);
	vector<int> dice(m);

	for (int i = 1; i <= n; i++)
		cin >> board[i];

	for (int i = 0; i < m; i++)
		cin >> dice[i];

	int cnt = 0;
	int cur = 1;

	while (cur <= n) {
		cur += dice[cnt++];
		if (cur >= n) break;
		cur += board[cur];
	}
	cout << cnt << '\n';
	return 0;
}