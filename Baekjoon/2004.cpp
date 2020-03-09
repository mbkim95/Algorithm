#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> getTwoFive(long long num) {
	long long two = 0, five = 0;

	for (long long i = 2; i <= num; i *= 2)
		two += num / i;
	for (long long i = 5; i <= num; i *= 5)
		five += num / i;
	return make_pair(two, five);
}

int main() {
	long long n, m;
	cin >> n >> m;
	pair<long long, long long> p1 = getTwoFive(n);
	pair<long long, long long> p2 = getTwoFive(n - m);
	pair<long long, long long> p3 = getTwoFive(m);
	cout << min(p1.first - p2.first - p3.first, p1.second - p2.second - p3.second) << '\n';
	return 0;
}