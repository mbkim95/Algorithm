#include <iostream>
#include <cmath>
using namespace std;

int cx1, cy1, cx2, cy2, r1, r2;

int main() {
	int t;
	cin >> t;
	while(t--){
		int ans;
		cin >> cx1 >> cy1 >> r1 >> cx2 >> cy2 >> r2;
		if (cx1 == cx2 && cy1 == cy2 && r1 == r2) {
			ans = -1;
		}
		else {
			int d = pow(cx1 - cx2, 2) + pow(cy1 - cy2, 2);
			int r = pow(r1 + r2, 2);
			int r_ = pow(r1 - r2, 2);
			if (d == r || d == r_)
				ans = 1;
			else if (d > r)
				ans = 0;
			else {
				if (r_ < d)
					ans = 2;
				else
					ans = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}