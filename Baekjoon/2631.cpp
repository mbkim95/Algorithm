#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int child[200];

int get_lis_length() {
	vector<int> lis;
	lis.push_back(child[0]);
	for (int i = 1; i < n; i++) {
		if (lis[lis.size() - 1] < child[i]) lis.push_back(child[i]);
		else {
			auto it = lower_bound(lis.begin(), lis.end(), child[i]);
			*it = child[i];
		}
	}
	return lis.size();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> child[i];
	cout << n - get_lis_length() << '\n';
	return 0;
}