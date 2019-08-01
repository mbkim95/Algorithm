#include <iostream>
using namespace std;

int main() {
	int n, ans;
	cin >> n;
	int tmp = (n - 1) / 4;

	if (tmp % 2) 	
		ans = 10 - (n % 8) == 10 ? 2 : 10 - (n % 8);
	else
		ans = n % 8;
	cout << ans << '\n';
	return 0;
}