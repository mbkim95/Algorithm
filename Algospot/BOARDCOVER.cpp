#include <iostream>
#include <cstring>
using namespace std;

int b[20][20];

int h, w;
int block[4][3][2] = {
	{ { 0, 0 },{ 1, 0 },{ 0, 1 } },
{ { 0, 0 },{ 0, 1 },{ 1, 1 } },
{ { 0, 0 },{ 1, 0 },{ 1, 1 } },
{ { 0, 0 },{ 1, 0 },{ 1, -1 } }
};

bool inRange(int x, int y) {
	return (0 <= x && x < w) && (0 <= y && y < h);
}

bool set(int x, int y, int type, int delta) {
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		int ny = y + block[type][i][0];
		int nx = x + block[type][i][1];

		if (!inRange(nx, ny))
			ok = false
		else if ((b[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover() {
	int y = -1, x = -1;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			if (!b[i][j]) {
				y = i;
				x = j;
				break;
			}
		if (y != -1)
			break;
	}

	if (y == -1)
		return 1;

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		if (set(x, y, i, 1))
			ret += cover();
		set(x, y, i, -1);
	}
	return ret;
}

bool isPossible() {
	int cnt = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (b[i][j] == 0)
				cnt++;
		}
	}
	return cnt % 3 == 0 ? true : false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w;

		memset(b, 0, sizeof(b));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char tmp;
				cin >> tmp;
				if (tmp == '.')
					b[i][j] = 0;
				else
					b[i][j] = 1;
			}
		}

		int ans = 0;

		if (isPossible()) {
			ans = cover();
		}

		cout << ans << '\n';
	}
}