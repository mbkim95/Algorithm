#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, v;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> v;
	cout << count(a.begin(), a.end(), v) << '\n';

	return 0;
}