#include <iostream>
#include <algorithm>
using namespace std;

int n, m, pr, pc;
char space[501][501];
const int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };

bool inRange(int x, int y) {
	return (1 <= x && x <= m) && (1 <= y && y <= n);
}

int change_dir(char planet, int cur_dir) {
	if (planet == '/') {
		if (cur_dir == 0) return 1;
		if (cur_dir == 1) return 0;
		if (cur_dir == 2) return 3;
		if (cur_dir == 3) return 2;
	}
	else {
		if (cur_dir == 0) return 3;
		if (cur_dir == 1) return 2;
		if (cur_dir == 2) return 1;
		if (cur_dir == 3) return 0;
	}
}

int simulation(int dir) {
	int x = pc; 
	int y = pr; 
	int d = dir; 
	int cnt = 0;

	while(true){
		if (cnt > n * m) break;
		if(!inRange(x, y) || space[y][x] == 'C') return cnt;
		if (space[y][x] == '/' || space[y][x] == '\\') d = change_dir(space[y][x], d);
		x += dx[d]; y += dy[d];
		cnt++;
	}
	return 987654321;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> space[i][j];
	cin >> pr >> pc;

	int ans = 0, dir;
	for (int i = 0; i < 4; i++) {
		int tmp = simulation(i);
		if (ans < tmp) {
			ans = tmp;
			dir = i;
		}
	}
	if (dir == 0) cout << "U\n";
	else if (dir == 1) cout << "R\n";
	else if (dir == 2) cout << "D\n";
	else cout << "L\n";

	if (ans == 987654321) cout << "Voyager\n";
	else cout << ans << '\n';
	return 0;
}