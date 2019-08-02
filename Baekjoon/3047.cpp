#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> num = vector<int>(3);
	char ch[3];
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < 3; i++) {
		cin >> ch[i];
	}

	for (int i = 0; i < 3; i++) {
		char c = ch[i];
		int out;
		if (c == 'A')
			out = num[0];
		else if (c == 'B')
			out = num[1];
		else
			out = num[2];
		cout << out << ' ';
	}
	cout << '\n';
	return 0;
}