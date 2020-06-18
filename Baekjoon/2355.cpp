#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	long long ans = (b * (b+1) - a * (a-1)) / 2;
	cout << ans << '\n';
	return 0;
}