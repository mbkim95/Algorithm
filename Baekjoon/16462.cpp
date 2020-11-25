#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	string x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 0; j < x.length(); j++)
			if (x[j] == '0' || x[j] == '6')
				x[j] = '9';
		sum += min(100, stoi(x));
	}
	cout << round((double)sum / n) << '\n';
	return 0;
}