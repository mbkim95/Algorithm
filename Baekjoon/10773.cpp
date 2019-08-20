#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	vector<int>money;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		if (tmp != 0)
			money.push_back(tmp);
		else
			money.pop_back();
	}
	long long ans = 0;
	for (int i = 0; i < money.size(); i++)
		ans += money[i];
	cout << ans << '\n';
	return 0;
}
