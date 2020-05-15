#include <iostream>
#include <cstring>
using namespace std;

bool room[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(room, false, sizeof(room));
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i)
				room[j] = !room[j];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (room[i]) ans++;
		cout << ans << '\n';
	}
	return 0;
}