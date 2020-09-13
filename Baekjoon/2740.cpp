#include <iostream>
#include <vector>
using namespace std;

int n1, n2, m1, m2;
vector<vector<int>> arr1, arr2;

void solve() {
	int n = arr1.size(), m = arr2[0].size();
	vector<vector<int>> result(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = 0; k < arr1[i].size(); k++) {
				sum += (arr1[i][k] * arr2[k][j]);
			}
			result[i][j] = sum;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n1 >> m1;
	arr1 = vector<vector<int>>(n1, vector<int>(m1));
	for (int i = 0; i < n1; i++) for (int j = 0; j < m1; j++) cin >> arr1[i][j];
	cin >> n2 >> m2;
	arr2 = vector<vector<int>>(n2, vector<int>(m2));
	for (int i = 0; i < n2; i++) for (int j = 0; j < m2; j++) cin >> arr2[i][j];
	solve();
	return 0;
}