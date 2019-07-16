#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int b[1000];

int getView(int idx) {
	int ret = 0;

	for (int i = -2; i <= 2; i++) {
		if (i == 0)
			continue;
		if (b[idx] <= b[idx + i]) {
			return 0;
		}
		else {
			ret = max(ret, b[idx + i]);
		}
	}
	return b[idx] - ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	int num, ans;
	for (int t = 1; t <= 10; t++) {
		ans = 0;
		cin >> num;
		memset(b, 0, sizeof(b));
		for(int i=0; i<num; i++)
			cin >> b[i];
		
		for (int i = 2; i < num-1; i++) {
			ans += getView(i);
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
	return 0;
}