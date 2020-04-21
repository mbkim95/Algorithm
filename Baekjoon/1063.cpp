#include <iostream>
#include <map>
using namespace std;

bool inRange(char x, char y) {
	return ('A' <= x && x <= 'H') && ('1' <= y && y <= '8');
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<string, pair<int, int>> map = { {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}}, {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}} };
	int n;
	string s1, s2;
	cin >> s1 >> s2 >> n;
	char kx = s1[0], ky = s1[1], sx = s2[0], sy = s2[1];

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		int x = map[tmp].first; int y = map[tmp].second;
		// 킹이 이동할 수 없는 경우
		if (!inRange(kx + x, ky + y)) continue;
		// 킹이 돌의 위치로 이동하는 경우
		if (kx + x == sx && ky + y == sy) {
			// 돌이 이동할 수 없는 경우
			if(!inRange(sx + x, sy + y)) continue;
			sx += x; sy += y;
		}
		kx += x; ky += y;
	}
	cout << kx << ky << '\n' << sx << sy << '\n';
	return 0;
}