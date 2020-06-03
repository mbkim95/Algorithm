#include <iostream>
using namespace std;
typedef long long ll;

long long gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	for (int i = 0; i < gcd(a,b); i++)
		cout << 1;
	cout << '\n';
	return 0;
}