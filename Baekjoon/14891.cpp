#include <iostream>
#include <queue>
using namespace std;

int k;
int wheel[4][8];
queue<pair<int, int>>q;

void turnWheel(int num, int dir) {
	if (dir == 1) {
		int tmp = wheel[num][7];
		for (int i = 7; i >= 1; i--) {
			wheel[num][i] = wheel[num][i - 1];
		}
		wheel[num][0] = tmp;
	}
	else {
		int tmp = wheel[num][0];
		for (int i = 0; i < 7; i++) {
			wheel[num][i] = wheel[num][i + 1];
		}
		wheel[num][7] = tmp;
	}
}

int calcScore() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) {
			if (i == 0)
				sum += 1;
			else if (i == 1)
				sum += 2;
			else if (i == 2)
				sum += 4;
			else
				sum += 8;
		}
	}
	return sum;
}

void checkWheels(int num, int dir) {
	q.push(make_pair(num, dir));
	if (num == 0) {
		if (wheel[0][2] != wheel[1][6]) {
			q.push(make_pair(1, !dir));
			if (wheel[1][2] != wheel[2][6]) {
				q.push(make_pair(2, dir));
				if (wheel[2][2] != wheel[3][6])
					q.push(make_pair(3, !dir));
			}
		}
	}
	else if (num == 1) {
		if (wheel[0][2] != wheel[1][6])
			q.push(make_pair(0, !dir));
		if (wheel[1][2] != wheel[2][6]) {
			q.push(make_pair(2, !dir));
			if (wheel[2][2] != wheel[3][6])
				q.push(make_pair(3, dir));
		}
	}
	else if (num == 2) {
		if (wheel[2][2] != wheel[3][6])
			q.push(make_pair(3, !dir));
		if (wheel[1][2] != wheel[2][6]) {
			q.push(make_pair(1, !dir));
			if (wheel[0][2] != wheel[1][6]) {
				q.push(make_pair(0, dir));
			}
		}
	}
	else {
		if (wheel[2][2] != wheel[3][6]) {
			q.push(make_pair(2, !dir));
			if (wheel[1][2] != wheel[2][6]) {
				q.push(make_pair(1, dir));
				if (wheel[0][2] != wheel[1][6])
					q.push(make_pair(0, !dir));
			}
		}
	}

}

void solve() {
	for (int i = 0; i < k; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		tmp1 -= 1;
		tmp2 = (tmp2 == -1 ? 0 : 1);
		checkWheels(tmp1, tmp2);
		while (!q.empty()) {
			pair<int, int> tmp;
			tmp = q.front();
			q.pop();
			turnWheel(tmp.first, tmp.second);
		}
	}
	printf("%d\n", calcScore());
}

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &wheel[i][j]);
	scanf("%d", &k);
	solve();
	return 0;
}