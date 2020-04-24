#include <iostream>
#include <map>
using namespace std;

int num[5][5];
int ans[25];
bool is_inc, is_dec;
map<int, pair<int, int>> points;

bool check_row(int y) {
	for (int i = 0; i < 5; i++)
		if (num[y][i] != -1)
			return false;
	return true;
}

bool check_col(int x) {
	for (int i = 0; i < 5; i++)
		if (num[i][x] != -1) 
			return false;
	return true;
}

bool check_inc() {
	for (int i = 0; i < 5; i++)
		if (num[4 - i][i] != -1)
			return false;
	return true;
}

bool check_dec() {
	for (int i = 0; i < 5; i++)
		if (num[i][i] != -1) 
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> num[i][j];
			points[num[i][j]] = { j, i };
		}

	for (int i = 0; i < 25; i++) 
		cin >> ans[i];

	for (int i = 0; i < 25; i++) {
		int tmp = ans[i];
		int x = points[tmp].first;
		int y = points[tmp].second;
		num[y][x] = -1;
		if (check_col(x)) cnt++;
		if (check_row(y)) cnt++;
		if(!is_inc)
			if (check_inc()) {
				cnt++;
				is_inc = true;
			}
		if(!is_dec)
			if (check_dec()) {
				cnt++;
				is_dec = true;
			}

		if (cnt >= 3) {
			cout << i + 1 << '\n';
			break;
		}
	}
	return 0;
}