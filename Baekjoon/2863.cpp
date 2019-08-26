#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& mat) {
	vector<vector<int>> tmp = mat;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			mat[i][j] = tmp[1 - j][i];
}

void solve(vector<vector<int>>& mat) {
	int ans = 0;
	double max = 0.0;
	for (int i = 0; i <= 3; i++) {
		double sum = (double)mat[0][0] / mat[1][0] + (double)mat[0][1] / mat[1][1];
		if (sum > max) {
			max = sum;
			ans = i;
		}
		rotate(mat);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<int>> mat(2, vector<int>(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> mat[i][j];
	solve(mat);
	return 0;
}