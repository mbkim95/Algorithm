#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int time[101] = { 0, };

	for (int i = 0; i < 3; i++) {
		int s, e;
		cin >> s >> e;
		for (int i = s; i < e; i++)
			time[i]++;
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		if (time[i] == 1) {
			ans += a;
		}
		else if (time[i] == 2) {
			ans += 2 * b;
		}
		else if (time[i] == 3) {
			ans += 3 * c;
		}
	}
	cout << ans << '\n';
	return 0;
}