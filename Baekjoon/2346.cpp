#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v.push_back(make_pair(i, num));
	}
	while (v.empty() != true) {
		cout << v.front().first << ' ';
		int a = v.front().second;
		v.erase(v.begin());

		if (a < 0) {
			for (int j = 0; j < abs(a); j++) {
				v.insert(v.begin(), v.back());
				v.erase(v.end());
			}
		}
		else {
			for (int j = 0; j < a - 1; j++) {
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
	}
	return 0;
}