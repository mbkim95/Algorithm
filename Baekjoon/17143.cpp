#include <iostream>
#include <vector>
using namespace std;

struct SHARK {
	bool moved;
	int speed, dir, size;
};

int r, c, m;

void moveShark(vector<vector<vector<SHARK>>>& map) {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].size() > 0 && map[i][j][0].moved == false) {
				int x = j, y = i;
				SHARK shark = map[i][j][0];
				if (shark.dir == 1 || shark.dir == 2) {
					if (shark.dir == 1)	y -= shark.speed;
					else y += shark.speed;
					while (true) {
						if (1 <= y && y <= r) break;
						if (y < 1) {
							y = 2 - y;
							shark.dir = 2;
						}
						else if (y > r) {
							y = 2 * r - y;
							shark.dir = 1;
						}
					}
				}
				else if (shark.dir == 3 || shark.dir == 4) {
					if (shark.dir == 3) x += shark.speed;
					else x -= shark.speed;
					while (true) {
						if (1 <= x && x <= c) break;
						if (x < 1) {
							x = 2 - x;
							shark.dir = 3;
						}
						else if (x > c) {
							x = 2 * c - x;
							shark.dir = 4;
						}
					}
				}
				shark.moved = true;
				map[y][x].push_back(shark);
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].size() > 1) {
				int size = 0;
				SHARK tmp;
				for (int l = 0; l < map[i][j].size(); l++) {
					if (map[i][j][l].moved && size < map[i][j][l].size) {
						tmp = map[i][j][l];
						size = map[i][j][l].size;
					}
				}
				map[i][j].clear();
				tmp.moved = false;
				map[i][j].push_back(tmp);
			}
			else if (map[i][j].size() == 1 && map[i][j][0].moved)
				map[i][j][0].moved = false;
			else if (map[i][j].size() == 1 && !map[i][j][0].moved)
				map[i][j].clear();
		}
	}
}

int solve(vector<vector<vector<SHARK>>>& map) {
	int fisher = 0;
	int total = 0;
	while (fisher != c) {
		fisher++;
		int i;
		for (i = 1; i <= r; i++) {
			if (map[i][fisher].size() > 0) {
				total += map[i][fisher][0].size;
				map[i][fisher].pop_back();
				break;
			}
		}
		moveShark(map);
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> m;
	vector<vector<vector<SHARK>>> map(r + 1, vector<vector<SHARK>>(c + 1));
	for (int i = 0; i < m; i++) {
		int x, y, s, d, z;
		cin >> y >> x >> s >> d >> z;
		SHARK shark = { false, s, d, z };
		map[y][x].push_back(shark);
	}
	cout << solve(map) << '\n';
	return 0;
}