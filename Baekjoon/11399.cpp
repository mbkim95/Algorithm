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
	int t = v[0];
	for (int i = 1; i < n; i++) {
		int tmp = v[i];
		v[i] += t;
		t += tmp;
	}
	t = 0;
	for (int i = 0; i < n; i++)
		t += v[i];
	cout << t << '\n';
}