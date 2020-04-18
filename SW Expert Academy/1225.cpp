#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 10;
	list<int> list;
	while (t--) {
		list.clear();
		int num;
		cin >> num;
		for (int i = 0; i < 8; i++) {
			int tmp;
			cin >> tmp;
			list.push_back(tmp);
		}
		int diff = 1;
		while (true) {
			if (diff == 6) diff = 1;
			int next = list.front() - diff;
			list.pop_front();
			if (next <= 0) {
				list.push_back(0);
				break;
			}
			list.push_back(next);
			diff++;
		}
		cout << '#' << num << ' ';
		for (int v : list) cout << v << ' ';
		cout << '\n';
	}
}