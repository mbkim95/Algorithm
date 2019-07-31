#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, m, ans;
deque<int> dq;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		int idx;
		for (int j = 0; j < dq.size(); j++) {
			if (num == dq[j]) {
				idx = j;
				break;
			}
		}
		if (idx > dq.size() - idx) {
			for (int j = 0; j < dq.size() - idx; j++) {
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
			ans += dq.size() - idx;
		}
		else {
			for (int i = 0; i < idx; i++) {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
			ans += idx;
		}
		dq.pop_front();
	}
	cout << ans << '\n';
	return 0;
}