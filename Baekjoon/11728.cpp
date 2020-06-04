#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + m);
	for (int i = 0; i < n + m; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}