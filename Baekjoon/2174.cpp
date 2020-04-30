#include <iostream>
#include <map>
using namespace std;

struct robot {
	int x, y, dir;
};

int a, b, n, m;
robot r[101];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

bool inRange(int x, int y) {
	return (1 <= x && x <= a) && (1 <= y && y <= b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp1, tmp2;
		char tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		r[i].x = tmp1;
		r[i].y = tmp2;
		if (tmp3 == 'N') r[i].dir = 0;
		else if (tmp3 == 'E') r[i].dir = 1;
		else if (tmp3 == 'S') r[i].dir = 2;
		else r[i].dir = 3;
	}

	for (int i = 0; i < m; i++) {
		int num, repeat;
		char cmd;
		cin >> num >> cmd >> repeat;
		for (int j = 0; j < repeat; j++) {
			if (cmd == 'F') {
				r[num].x += dx[r[num].dir];
				r[num].y += dy[r[num].dir];
				if (!inRange(r[num].x, r[num].y)) {
					cout << "Robot " << num << " crashes into the wall\n";
					exit(0);
				}
				for (int l = 1; l <= n; l++) {
					if (l == num) continue;
					if (r[num].x == r[l].x && r[num].y == r[l].y) {
						cout << "Robot " << num << " crashes into robot " << l << '\n';
						exit(0);
					}
				}
			}
			else if (cmd == 'R') r[num].dir = (r[num].dir + 1) % 4;
			else r[num].dir = (r[num].dir - 1 + 4) % 4;
		}
	}
	cout << "OK\n";
	return 0;
}