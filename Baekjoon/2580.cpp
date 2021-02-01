#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int> > v;

bool checkVertical(int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][x] == num)
			return false;
	}
	return true;
}

bool checkHorizontal(int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[y][i] == num)
			return false;
	}
	return true;
}

bool checkSquare(int x, int y, int num) {
	int tmp_x = (x / 3) * 3;
	int tmp_y = (y / 3) * 3;
	
	for (int i = tmp_y; i < tmp_y + 3; i++) {
		for (int j = tmp_x; j < tmp_x + 3; j++)
			if (sudoku[i][j] == num)
				return false;
	}
	return true;
}

void dfs(int idx) {
	if(idx == v.size()){
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++) {
		int x = v[idx].first;
		int y = v[idx].second;

		if (checkVertical(x, i) && checkHorizontal(y, i) && checkSquare(x, y, i)) {
			sudoku[y][x] = i;
			dfs(idx + 1);
			sudoku[y][x] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				v.push_back(make_pair(j, i));
		}
	}
	dfs(0);
	return 0;
}
