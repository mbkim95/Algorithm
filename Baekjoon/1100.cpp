#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> b;

int main() {
	b = vector<vector<char>>(8, vector<char>(8));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> b[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int j;
		if (i % 2)
			j = 1;
		else
			j = 0;
		for (; j < 8; j += 2) {
			if (b[i][j] == 'F')
				cnt++;
		}
	}
	cout << cnt << '\n';
}
