#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	priority_queue<int>q[n + 1];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int line, pret;
		cin >> line >> pret;
		if (q[line].empty()) {
			q[line].push(pret);
			ans++;
		}else if (q[line].top() > pret) {
			while (!q[line].empty() && q[line].top() > pret) {
				q[line].pop();
				ans++;
			}
			if (q[line].top() != pret) {
				q[line].push(pret);
				ans++;
			}
		}
		else if (q[line].top() < pret) {
			q[line].push(pret);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}