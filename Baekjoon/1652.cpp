#include <iostream>
using namespace std;

int n;
char room[100][100];

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> room[i][j];

	int answer = 0;
	for (int i = 0; i < n; i++) {
		int prev = 0;
		for (int j = 0; j <= n; j++) {
			if (j == n || room[i][j] == 'X') {
				if (j - prev >= 2) {
					answer++;
				}
				prev = j + 1;
			}
		}
	}
	cout << answer << ' ';
	answer = 0;

	for (int j = 0; j < n; j++) {
		int prev = 0;
		for (int i = 0; i <= n; i++) {
			if (i == n || room[i][j] == 'X') {
				if (i - prev >= 2) {
					answer++;
				}
				prev = i + 1;
			}
		}
	}

	cout << answer << '\n';
	return 0;
}