#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> data;

void precalc() {
	for (int i = 0; i <= 10; i++) {
		data[i].push_back(0);
		for (int j = 1; j <= 4; j++) {
			int tmp = (int)pow(i, j) % 10;
			if (tmp == 0)
				tmp = 10;
			bool find = false;
			for (int k = 1; k < data[i].size(); k++) {
				if (data[i][k] == tmp) {
					find = true;
					break;
				}
			}
			if (find)
				break;
			else
				data[i].push_back(tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	data = vector<vector<int>>(11);
	precalc();

	while (t--) {
		int a, b;
		cin >> a >> b;
		a %= 10;
		if (b % (data[a].size() - 1) == 0)
			b = (data[a].size() - 1);
		else
			b %= (data[a].size() - 1);
		cout << data[a][b] << '\n';
	}
	return 0;
}