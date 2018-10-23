#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char b[5][5];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < 5) && (0 <= y && y < 5);
}

bool hasWord(int x, int y, string word) {
	if (!inRange(x, y))
		return false;

	if (word[0] != b[y][x])
		return false;

	if (word.size() == 1)
		return true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (hasWord(nx, ny, word.substr(1)))
			return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> b[i][j];
		
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			string str;
			cin >> str;
			bool find = false;

			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					find = hasWord(k, j, str);
					if (find == true)
						goto answer;
				}
			}
		answer:
			if (find)
				cout << str << " YES\n";
			else
				cout << str << " NO\n";
		}
	}
}