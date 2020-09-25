#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> soldiers;

int get_lis() {
	if (n == 1) return 0;
	vector<int> lis;
	lis.push_back(soldiers[0]);

	for (int i = 1; i < n; i++) {
		if (lis[lis.size() - 1] < soldiers[i]) lis.push_back(soldiers[i]);
		else {
			auto it = lower_bound(lis.begin(), lis.end(), soldiers[i]);
			*it = soldiers[i];
		}
	}
	return n - lis.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	soldiers = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> soldiers[i];
	reverse(soldiers.begin(), soldiers.end());
	cout << get_lis() << '\n';
	return 0;
}