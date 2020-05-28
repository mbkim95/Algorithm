#include <iostream>
using namespace std;

int n, f;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int row, col;
	int max_value = 0;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int tmp;
			cin >> tmp;
			if (max_value < tmp) {
				max_value = tmp;
				row = i;
				col = j;
			}
		}
	}
	cout << max_value << '\n' << row << ' ' << col << '\n';
	return 0;
}