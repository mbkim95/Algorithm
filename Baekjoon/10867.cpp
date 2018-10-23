#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	ios_base::sync_with_stdio(false);
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}