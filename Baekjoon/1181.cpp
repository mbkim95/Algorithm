#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), [](string a, string b) {
		return make_pair(a.size(), a) < make_pair(b.size(), b);
	});

	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto x : v)
		cout << x << '\n';
	return 0;
}