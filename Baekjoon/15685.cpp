#include <iostream>
#include <vector>
using namespace std;

int n;
int map[101][101];
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 };

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> curve;
		curve.push_back(d);
		map[y][x] = 1;
		x += dx[d];
		y += dy[d];
		map[y][x] = 1;
		for (int j = 1; j <= g; j++) {
			for (int k = curve.size() - 1; k >= 0; k--) {
				int dir = (curve[k] + 1) % 4;
				x += dx[dir];
				y += dy[dir];
				map[y][x] = 1;
				curve.push_back(dir);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) ans++;
	cout << ans << '\n';
	return 0;
}