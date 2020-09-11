#include <iostream>
#include <vector>
using namespace std;

int n;
int a[1000001];
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	lis.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (lis.back() < a[i]) lis.push_back(a[i]);
		else {
			auto it = lower_bound(lis.begin(), lis.end(), a[i]);
			*it = a[i];
		}
	}
	cout << lis.size() - 1 << '\n';
	return 0;
}