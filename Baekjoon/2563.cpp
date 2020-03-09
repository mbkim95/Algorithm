#include <iostream>
using namespace std;

int n;
bool paper[101][101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				paper[y + i][x + j] = true;

	}

	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (paper[i][j])
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}