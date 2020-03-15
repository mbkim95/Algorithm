#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	bool flag = true;
	while (next_permutation(num.begin(), num.end())) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << ' ';
		}
		flag = false;
		break;
	}
	if (!flag)
		cout << '\n';
	else
		cout << "-1\n";
	return 0;
}