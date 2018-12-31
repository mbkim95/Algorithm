#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h, start_x, start_y;
vector<pair<int, int>> fire;
vector<vector<char>> map;
vector<vector<bool>> visited;
const int dx[4] = { -1, 1, 0 ,0 }, dy[4] = { 0, 0, -1, 1 };

bool canEscape(int x, int y) {
	return (x < 0 || x >= w) || (y < 0 || y >= h);
}

int bfs() {
	queue<pair<int, int>>q1, q2;
	q1.push(make_pair(start_x, start_y));
	for (int i = 0; i < fire.size(); i++) 
		q2.push(make_pair(fire[i].first, fire[i].second));
	int time = 0;

	while (!q1.empty()) {
		int size = q2.size();

		while (size--) {
			pair<int, int> tmp = q2.front();
			q2.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = tmp.first + dx[i];
				int nextY = tmp.second + dy[i];
				if (!canEscape(nextX, nextY) && (map[nextY][nextX] == '@' || map[nextY][nextX] == '.')) {
					map[nextY][nextX] = '*';
					q2.push(make_pair(nextX, nextY));
				}
			}
		}
		size = q1.size();
		
		while (size--) {
			pair<int, int> tmp = q1.front();
			q1.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = tmp.first + dx[i];
				int nextY = tmp.second + dy[i];

				if (canEscape(nextX, nextY)) {
					return time + 1;
				}
				if(map[nextY][nextX] == '.'){
					map[nextY][nextX] = '@';
					q1.push(make_pair(nextX, nextY));
				}
				
			}
		}
		time++;
	}	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> w >> h;
		fire.clear();
		map = vector<vector<char>>(h, vector<char>(w, 0));
		visited = vector<vector<bool>>(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) {
				char tmp;
				cin >> tmp;
				map[i][j] = tmp;
				if (tmp == '@') {
					start_x = j;
					start_y = i;
				}
				else if (tmp == '*') {
					fire.push_back(make_pair(j, i));
				}
			}
		int ans = bfs();
		ans == -1 ? cout << "IMPOSSIBLE\n" : cout << ans << '\n';
	}
	return 0;
}