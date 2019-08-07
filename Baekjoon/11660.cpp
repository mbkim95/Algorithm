#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>mat;
int x1, y1, x2, y2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	mat = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			mat[i + 1][j + 1] = mat[i][j + 1] + mat[i + 1][j] - mat[i][j] + tmp;
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << mat[x2][y2] - mat[x1 - 1][y2] - mat[x2][y1 - 1] + mat[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}