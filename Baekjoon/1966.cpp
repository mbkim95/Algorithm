#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, p[11];

bool canPop(int v) {
	for (int i = 10; i > v; i--)
		if (p[i] > 0) return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		memset(p, 0, sizeof(p));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			p[tmp]++;
			q.push({ i, tmp });
		}
		int cnt = 0;
		while (true) {
			pair<int, int> tmp = q.front();
			q.pop();

			if (canPop(tmp.second)) {
				cnt++;
				p[tmp.second]--;
				if (tmp.first == m) break;
			}
			else q.push(tmp);		
		}
		cout << cnt << '\n';
	}
	return 0;
}
