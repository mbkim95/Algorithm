#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	int ans = min(n/2, m);
	while (k > 0) {

		int team_n = n / 2;
		int team_m = m;

		if ((team_n == team_m || team_n > team_m)){
			n -= 2;
			k -= 2;
		}
		else if (team_n < team_m) {
			m--;
			k--;
		}
		ans = min(n / 2, m);
	}
	cout << ans << '\n';
	return 0;
}