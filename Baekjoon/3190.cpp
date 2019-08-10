#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

int n, k, l, dir;
int hx, hy, tx, ty;
list<pair<int, int>> apple;
vector<pair<int, char>> cmd;
deque<pair<int, int>> snake;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

bool inRange(int x, int y) {
	return (1 <= x && x <= n) && (1 <= y && y <= n);
}

bool gameover() {
	for (int i = 1; i < snake.size(); i++) {
		pair<int, int>tmp = snake.at(i);
		if (tmp.first == hx && tmp.second == hy)
			return true;
	}
	return false;
}

bool eatApple() {
	list<pair<int, int>>::iterator it;
	for (it = apple.begin(); it != apple.end(); it++) {
		if (hx == it->first && hy == it->second) {
			apple.erase(it++);
			return true;
		}
	}
	return false;
}

void solve() {
	int t = 0;
	hx = hy = tx = ty = 1;
	dir = 0;
	int idx = 0;
	while (true) {
		t++;
		hx += dx[dir];
		hy += dy[dir];
		snake.push_front(make_pair(hx, hy));

		if (gameover() || !inRange(hx, hy))
			break;

		if (!eatApple()) {
			snake.pop_back();
			tx = snake.back().first;
			ty = snake.back().second;
		}
		if (cmd[idx].first == t) {
			if (cmd[idx].second == 'L') {
				if (dir == 0)
					dir = 4;
				dir--;
			}
			else {
				if (dir == 3)
					dir = -1;
				dir++;
			}
			idx++;
		}

	}
	cout << t << '\n';
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		apple.push_back(make_pair(tmp2, tmp1));
	}
	eatApple();
	snake.push_back(make_pair(1, 1));
	cin >> l;
	cmd = vector<pair<int, char>>(l);
	for (int i = 0; i < l; i++)
		cin >> cmd[i].first >> cmd[i].second;
	solve();
	return 0;
}