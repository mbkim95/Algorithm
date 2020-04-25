#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int room[201];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int c = 1; c <= t; c++) {
		int n;
		cin >> n;
		fill(room, room + 201, 0);
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);
			if (a % 2 == 1) a++;
			if (b % 2 == 1) b++;
			a /= 2;
			b /= 2;
			for (int j = a; j <= b; j++)
				room[j]++;
		}
		int ans = 0;
		for (int i = 0; i <= 200; i++)
			ans = max(ans, room[i]);
		cout << "#" << c << ' ' << ans << '\n';
	}
}