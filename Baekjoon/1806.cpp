#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	vector<int> num(n);
	
	for (int& i : num)
		cin >> i;

	int start = 0, end = 0;
	int sum = 0;
	int ans = 100001;

	while (true) {
		if (sum >= s) {
			ans = min(ans, end - start);
			sum -= num[start++];
		}
		else if (end == n) break;
		else sum += num[end++];
	}
	cout << (ans == 100001 ? 0 : ans) << '\n';
	return 0;
	
}