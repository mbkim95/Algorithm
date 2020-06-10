#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	while (true) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) break;
		if (tmp % n == 0) cout << tmp << " is a multiple of " << n << ".\n";
		else cout << tmp << " is NOT a multiple of " << n << ".\n";
	}
	return 0;
}