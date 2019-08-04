#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;

bool is666(int num) {
	int chk = 0;
	int tmp;
	while (num > 0) {
		tmp = num % 10;
		num /= 10;
		if (tmp == 6)
			chk++;
		else
			chk = 0;
		if (chk == 3)
			return true;
	}
	return false;
}

void precalc() {
	num.push_back(0);
	for (int i = 666; i < 2666800; i++) {
		if (is666(i))
			num.push_back(i);
	}
}

int main() {
	cin >> n;
	precalc();
	cout << num[n] << '\n';
	return 0;
}