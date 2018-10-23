#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n;

int solve(int s, int e) {
	if (s == e) 
		return v[s];
	
	int mid = (s + e) / 2;

	int result = max(solve(s, mid), solve(mid + 1, e));

	int l = mid, r = mid + 1;
	int h = min(v[l], v[r]);

	result = max(result, 2 * h);

	while (s < l || r < e) {
		if (r < e && (l == s || v[l - 1] < v[r + 1])) {
			r++;
			h = min(h, v[r]);
		}
		else {
			l--;
			h = min(h, v[l]);
		}
		result = max(result, h*(r-l+1));
	}
	return result;
}

int main() {	
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << solve(0, n) << endl;
}