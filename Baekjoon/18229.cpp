#include <iostream>
using namespace std;

int n, m, k;
int p[101][101], total[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> p[i][j];

	bool find = false;
	int i, j;
	for (j = 0; j < m; j++) {
		for (i = 0; i < n; i++) {
			total[i] += p[i][j];
			if (total[i] >= k) {
				find = true;
				break;
			}
		}
		if (find) break;
	}
	cout << i + 1 << ' ' << j + 1 << '\n';
	return 0;
}