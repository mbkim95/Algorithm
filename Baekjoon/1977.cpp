#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int m, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	int a = sqrt(m);
	int b = sqrt(n);
	if (a * a != m)
		a++;
	int sum = 0;
	int ans;
	bool find = false;
	for (int i = a; i <= b; i++) {
		if (i == a)
			ans = (i*i);
		sum += (i*i);
		find = true;
	}
	if (find)
		cout << sum << '\n' << ans << '\n';
	else
		cout << -1 << '\n';
	return 0;
}
