#include <iostream>
#include <vector>
using namespace std;

int radder[100][100];
vector<int> start;

bool can_finish(int pos) {
	int y = 0;
	int x = pos;

	while (y < 99) {
		if (x < 99 && radder[y][x + 1] == 1) while (x < 99 && radder[y][x + 1] == 1) x++;
		else if (x > 0 && radder[y][x - 1] == 1) while (x > 0 && radder[y][x - 1] == 1) x--;
		y++;
	}
	if (radder[y][x] == 2) return true;
	return false;
}

int main() {
	int idx = 1;
	for (int c = 1; c <= 10; c++) {
		int tmp;
		cin >> tmp;
		start.clear();
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> radder[i][j];
				if (i == 0 && radder[i][j] == 1) start.push_back(j);
			}
		}

		for (int s : start) {
			if (can_finish(s)) {
				cout << "#" << c << ' ' << s << '\n';
			}
		}
	}
	return 0;
}