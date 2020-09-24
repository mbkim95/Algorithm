#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num;

int two_pointer() {
	int left = 0;
	int right = 0;
	int last_value = 0;
	int ret = 0;

	while (true) {
		if (left == right) {
			last_value = num[right];
			right++;
			ret = max(ret, right - left);
		}
		else if (right == n) break;
		else if (num[right] >= last_value) {
			last_value = num[right];
			right++;
			ret= max(ret, right - left);
		}
		else left++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	num = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int answer = two_pointer();
	reverse(num.begin(), num.end());
	answer = max(answer, two_pointer());
	cout << answer << '\n';
	return 0;
}