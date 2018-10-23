#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i] * (n - i));
	}
	cout << ans << '\n';	
}