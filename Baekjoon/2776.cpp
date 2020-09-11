#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int n, m;
	unordered_set<int> s;

	while (t--) {
		cin >> n;
		s.clear();
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			s.insert(tmp);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int tmp;
			cin >> tmp;
			if (s.find(tmp) != s.end()) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}