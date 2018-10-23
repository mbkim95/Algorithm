#include <iostream>
using namespace std;

int main() {
	int n, x;
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	auto ans = [&x](int num) {
		if (num < x)
			cout << num << ' ';
	};
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ans(tmp);
	}
	cout << '\n';
}