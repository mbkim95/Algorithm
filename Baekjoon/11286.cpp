#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (!q.empty()) {
				cout << q.top().second << '\n';
				q.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			q.push(make_pair(abs(tmp), tmp));
		}
	}
	return 0;
}