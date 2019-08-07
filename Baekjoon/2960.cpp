#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<bool> prime;

int solve() {
	int cnt = 0;
	prime = vector<bool>(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			prime[i] = false;
			cnt++;
			if (cnt == k)
				return i;
			for (int j = i * i; j <= n; j += i) {
				if (prime[j]) {
					prime[j] = false;
					cnt++;
					if (cnt == k)
						return j;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cout << solve() << '\n';
	return 0;
}