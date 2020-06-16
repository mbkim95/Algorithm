#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, max_v = 0, min_v = 1000;
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		max_v = max(max_v, tmp);
		min_v = min(min_v, tmp);
	}
	cout << max_v - min_v << '\n';
	return 0;
}