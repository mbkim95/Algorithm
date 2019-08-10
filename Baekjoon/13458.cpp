#include <iostream>
#include <vector>
using namespace std;

int n, b, c;
long long ans;
vector<int>a;

bool isFinish() {
	for (int i = 0; i < n; i++) {
		if (a[i] > 0)
			return false;
	}
	return true;
}

int main() {
	cin >> n;
	a = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		a[i] -= b;
		ans++;
	}

	while (!isFinish()) {
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				if (a[i] % c == 0) {
					ans += (a[i] / c);
					a[i] = 0;
				}
				else {
					ans += (a[i] / c + 1);
					a[i] = -1;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}