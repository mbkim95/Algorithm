#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num, decr, incr;

int calcDecrease(int idx) {
	int& ret = decr[idx];

	if (ret != -1)
		return ret;

	ret = 1;
	
	for (int i = idx+ 1; i < n; i++) {
		if (num[idx] > num[i])
			ret = max(ret, 1 + calcDecrease(i));
	}
	return ret;
}

int calcIncrease(int idx) {
	int& ret = incr[idx];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = idx - 1; i >= 0; i--) {
		if (num[idx] > num[i])
			ret = max(ret, 1 + calcIncrease(i));
	}
	return ret;
}

int main() {
	cin >> n;
	num = vector<int>(n);
	decr = vector<int>(n, -1);
	incr = vector<int>(n, -1);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		calcDecrease(i);
		calcIncrease(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, incr[i] + decr[i] - 1);
	}
	cout << ans << '\n';
	return 0;
}