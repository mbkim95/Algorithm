#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	int n;
	for (int i = 0; i < str.length(); i++) {
		n = str[i] - '0';
		v.push_back(n);
	}
	sort(v.begin(), v.end(), greater<int>());

	if (v[v.size() - 1] != 0) {
		cout << "-1\n";
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	if (sum % 3 == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}