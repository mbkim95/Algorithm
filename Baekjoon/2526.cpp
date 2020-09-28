#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	int num = n;
	set<int> s;
	set<int> overlap;
	while (true) {
		num *= n;
		num %= p;
		if (s.find(num) != s.end()) {
			if (overlap.find(num) != overlap.end()) break;
			else overlap.insert(num);
		}
		else {
			s.insert(num);
		}
	}
	cout << overlap.size() << '\n';
	return 0;
}