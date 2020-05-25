#include<iostream>
#include<cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long n, q;
	cin >> n;
	q = sqrtl(n);

	if (pow(q, 2) < n) cout << q + 1 << '\n';
	else cout << q << '\n';
	return 0;
}