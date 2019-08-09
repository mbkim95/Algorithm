#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> num;

int main() {
	int n;
	cin >> n;
	num = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num.begin(), num.end());
	int ans;
	if (n % 2) {
		int mid = (n - 1) / 2;
		ans = pow(num[mid], 2);
	}
	else {
		int mid = (n - 1) / 2;
		ans = num[mid] * num[mid + 1];
	}
	cout << ans << '\n';
	return 0;
}