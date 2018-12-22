#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	int c, n, k;
	cin >> c;
	while (c--) {
		cin >> n >> k;
		list<int> l;
		
		for (int i = 1; i <= n; i++)
			l.push_back(i);

		auto it = l.begin();
		while (n > 2) {
			it = l.erase(it);
			n--;
			if (it == l.end())
				it = l.begin();

			int cnt = (k - 1) % n;

			for (int i = 0; i < cnt; i++) {
				it++;
				if (it == l.end())
					it = l.begin();
			}	
		}

		cout << l.front() << ' ' << l.back() << '\n';
	}
	return 0;
}