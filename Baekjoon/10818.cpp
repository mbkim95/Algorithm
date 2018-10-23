#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	auto it = minmax_element(v.begin(), v.end());
	cout << *it.first << ' ' << *it.second << '\n';
	return 0;
}