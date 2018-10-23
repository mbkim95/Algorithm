#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int sum = 0;

	do {
		int tmp = 0;
		for (int i = 0; i < n-1; i++) {
			tmp += abs(v[i+1] - v[i]);
		}
		sum = max(sum, tmp);
	} while (next_permutation(v.begin(), v.end()));

	cout << sum << '\n';
	return 0;
}