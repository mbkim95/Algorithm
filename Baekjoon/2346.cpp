#include <iostream>
#include <list>
using namespace std;

int main() {
	int n;
	ios_base::sync_with_stdio(false);
	list<pair<int, int>> l;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		l.push_back(make_pair(tmp, i));
	}

	auto it = l.begin();
	for (int i = 0; i < n-1; i++) {
		cout << (it->second) << ' ';
		int step = it->first;
		if (step > 0) {
			auto temp = it;
			temp++;
			if (temp == l.end())
				temp = l.begin();
			l.erase(it);
			it = temp;
			for (int i = 1; i < step; i++) {
				it++;
				if (it == l.end())
					it = l.begin();
			}
		}
		else if (step < 0) {
			step = -step;
			auto temp = it;
			if (temp == l.begin())
				temp = l.end();
			temp--;
			l.erase(it);
			it = temp;
			for (int i = 1; i < step; i++) {
				it--;
				if (it == l.begin())
			 		it = l.end();
			}
		}
	}	
	cout << it->second << '\n';
}