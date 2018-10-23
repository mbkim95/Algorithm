#include <iostream>
#include <list>
using namespace std;

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, k;
		cin >> n >> k;
		list<int> l;

		for (int i = 1; i <= n; i++) {
			l.push_back(i);
		}
		
		auto it = l.begin();
		
		while (n > 2) {
			it = l.erase(it);
			if (it == l.end())
				it = l.begin();
			n--;
			for (int i = 0; i < k - 1; i++) {
				it++;
				if (it == l.end())
					it = l.begin();
			}
		}
		cout << l.front() << ' ' << l.back() << '\n';
	}
	return 0;
}