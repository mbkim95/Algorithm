#include <iostream>
#include <vector>
using namespace std;

int a, b;
vector<int> a_money, b_money;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	a_money = vector<int>(101, 0);
	b_money = vector<int>(65, 0);

	for (int i = 1; i <= 21; i++) {
		if (i == 1)
			a_money[i] = 500;
		else if (2 <= i && i < 4)
			a_money[i] = 300;
		else if (4 <= i && i < 7)
			a_money[i] = 200;
		else if (7 <= i && i < 11)
			a_money[i] = 50;
		else if (11 <= i && i < 16)
			a_money[i] = 30;
		else if (16 <= i && i < 22)
			a_money[i] = 10;
	}

	for (int i = 1; i <= 31; i++) {
		if (i == 1)
			b_money[i] = 512;
		else if (2 <= i && i < 4)
			b_money[i] = 256;
		else if (4 <= i && i < 8)
			b_money[i] = 128;
		else if (8 <= i && i < 16)
			b_money[i] = 64;
		else if (16 <= i && i < 32)
			b_money[i] = 32;
	}
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << (a_money[a] + b_money[b]) * 10000<< '\n';
	}
	return 0;
}