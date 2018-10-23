#include <iostream>
#include <algorithm>
using namespace std;

int c[16];
char s[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."};

void push(int button) {
	for (int i = 0; i < 16; i++) {
		if (s[button][i] == 'x')
			c[i] += 3;

		if (c[i] == 15)
			c[i] = 3;
	}
}

bool isFinished() {
	for (int i = 0; i < 16; i++) {
		if (c[i] % 12 != 0)
			return false;
	}
	return true;
}

int solve(int button) {
	if (button == 10)
		return isFinished() ? 0 : 9999;

	int ret = 9999;
	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + solve(button + 1));
		push(button);
	}

	return ret;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 16; i++)
			cin >> c[i];
		
		int ans = solve(0);

		if (ans == 9999)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}

	return 0;
}