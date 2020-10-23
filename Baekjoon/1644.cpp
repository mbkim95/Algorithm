#include <iostream>
#include <vector>
#define MAX 4000000
using namespace std;

int n;
int p[4000001];
vector<int> prime;

void pre_calc() {
	fill(p, p + MAX + 1, true);
	for (int i = 2; i * i <= MAX; i++) {
		if (p[i]) {
			int j = 2;
			while (i * j <= MAX) {
				p[i * j] = false;
				j++;
			}
		}
	}
	for (int i = 2; i <= MAX; i++)
		if (p[i])
			prime.push_back(i);
}

int two_pointer() {
	int ret = 0;
	int s = 0;
	int e = 0;
	int sum = prime[0];
	while (true) {
		if (s == prime.size() || e == prime.size()) break;
		else if (sum <= n) {
			if (sum == n) ret++;
			e++;
			sum += prime[e];
		}
		else {
			sum -= prime[s];
			s++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	pre_calc();
	cout << two_pointer() << '\n';
	return 0;
}