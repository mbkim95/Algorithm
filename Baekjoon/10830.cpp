#include <iostream>
#include <vector>
using namespace std;

int n;
long long b;

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
	vector<vector<int>> result(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

vector<vector<int>> pow(vector<vector<int>> &a, vector<vector<int>> &v, long long s) {
	if (s == 1) return v;
	vector<vector<int>> temp(n, vector<int>(n, 0));
	if (s % 2 == 0) {
		temp = pow(a, v, s / 2);
		return mul(temp, temp);
	}
	temp = pow(a, v, s - 1);
	return mul(temp, a);
}

int main() {
	cin >> n >> b;
	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<vector<int>> arr(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			v[i][j] = arr[i][j];
		}
	v = pow(arr, v, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << v[i][j] % 1000 << ' ';
		cout << '\n';
	}
	return 0;
}