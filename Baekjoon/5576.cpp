#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> w(10), k(10);
	for (int i = 0; i < 10; i++)
		cin >> w[i];
	for (int i = 0; i < 10; i++)
		cin >> k[i];
	sort(w.begin(), w.end());
	sort(k.begin(), k.end());
	cout << w[7] + w[8] + w[9] << ' ' << k[7] + k[8] + k[9] << '\n';
	return 0;
}