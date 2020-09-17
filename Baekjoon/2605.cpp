#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	list<int> l;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		auto it = l.end();
		while (tmp > 0) {
			tmp--;
			it--;
		}
		l.insert(it, i + 1);
	}

	for (int i : l) cout << i << ' ';
	cout << '\n';
	return 0;
}