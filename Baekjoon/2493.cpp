#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<pair<int, int>> s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		while (!s.empty()) {
			if (s.top().first > tmp) {
				cout << s.top().second << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty()) cout << 0 << ' ';
		s.push({ tmp, i });
	}
	cout << '\n';
	return 0;
}