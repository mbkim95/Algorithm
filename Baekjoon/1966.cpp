#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
queue<pair<int, int>> q;
vector<int> v;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		q = queue < pair<int, int>>();
		v.clear();
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			q.push(make_pair(tmp, i));
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		while (true) {
			pair<int, int> tmp = q.front();
			q.pop();			
			if (v[v.size() - 1] == tmp.first) {
				cnt++;
				v.pop_back();
				if (tmp.second == m)
					break;
			}
			else {
				q.push(tmp);
			}
		}
		cout << cnt << '\n';
	}
}