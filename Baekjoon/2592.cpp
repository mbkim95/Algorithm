#include <iostream>
using namespace std;

int count[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		count[tmp]++;
	}
	
	int m = 0;
	int ans = 0;
	for (int i = 10; i <= 1000; i += 10) {
		if (m < count[i]) {
			m = count[i];
			ans = i;
		}
	}
	cout << sum / 10 << '\n' << ans << '\n';
	return 0;
}