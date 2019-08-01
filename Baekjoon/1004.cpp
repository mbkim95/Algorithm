#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t;
	int x1, x2, y1, y2, cx, cy, r;
	cin >> t;
	while(t--){
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;
			int d1 = pow(x1 - cx, 2) + pow(y1 - cy, 2);
			int d2 = pow(x2 - cx, 2) + pow(y2 - cy, 2);
			r = pow(r, 2);			
			if ((d1 < r && d2 > r) || (d1 > r && d2 < r)) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}