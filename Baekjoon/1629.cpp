#include <iostream>
using namespace std;

long long a, b, c;

long long solve(long long n, long long k) {
	if (k == 0)
		return 1;

	long long tmp = solve(n, k / 2);
	long long result = tmp * tmp % c;

	if (k % 2 == 1)
		result = result * n % c;

	return result;
}


int main() {
	cin >> a >> b >> c;
	cout << solve(a, b) << endl;

}