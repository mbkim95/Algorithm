#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> rect[4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 4; i++)
			cin >> rect[i].first >> rect[i].second;
		sort(rect, rect + 4);
		int t1 = (rect[0].first - rect[1].first) * (rect[0].first - rect[1].first);
		int t2 = (rect[0].second - rect[1].second) * (rect[0].second - rect[1].second);
		int a = t1 + t2;

		int t3 = (rect[0].first - rect[2].first) * (rect[0].first - rect[2].first);
		int t4 = (rect[0].second - rect[2].second) * (rect[0].second - rect[2].second);
		int b = t3 + t4;

		int t5 = (rect[3].first - rect[1].first) * (rect[3].first - rect[1].first);
		int t6 = (rect[3].second - rect[1].second) * (rect[3].second - rect[1].second);
		int c = t5 + t6;

		int t7 = (rect[3].first - rect[2].first) * (rect[3].first - rect[2].first);
		int t8 = (rect[3].second - rect[2].second) * (rect[3].second - rect[2].second);
		int d = t7 + t8;

		int t9 = (rect[3].first - rect[0].first) * (rect[3].first - rect[0].first);
		int t10 = (rect[3].second - rect[0].second) * (rect[3].second - rect[0].second);
		int e = t9 + t10;

		int t11 = (rect[1].first - rect[2].first) * (rect[1].first - rect[2].first);
		int t12 = (rect[1].second - rect[2].second) * (rect[1].second - rect[2].second);
		int f = t11 + t12;

		if (a == b && b == c && c == d && d == a && e == f) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}