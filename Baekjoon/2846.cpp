#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int first;
	int prev;
	int answer = 0;
	cin >> prev;
	first = prev;
	for (int i = 1; i < n; i++) {
		int r;
		cin >> r;
		if (prev < r) {
			answer = answer > r - first ? answer : r - first;
		}
		else {
			first = r;
		}
		prev = r;
	}
	cout << answer << '\n';
	return 0;
}