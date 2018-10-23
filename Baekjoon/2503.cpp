#include <iostream>
#include <cstring>
using namespace std;

int chk[1000];
int q, s, b;

bool check(int num) {
	int n1, n2, n3, c1, c2, c3;
	int strike = 0, ball = 0;

	n1 = num / 100, n2 = num / 10 % 10, n3 = num % 10;
	c1 = q / 100, c2 = q / 10 % 10, c3 = q % 10;

	if (n1 == n2 || n1 == n3 || n2 == n3 || n2 == 0 || n3 == 0)
		return false;

	if (n1 == c1)	strike++;
	if (n2 == c2)	strike++;
	if (n3 == c3)	strike++;

	if (n1 == c2 || n1 == c3)	ball++;
	if (n2 == c1 || n2 == c3)	ball++;
	if (n3 == c1 || n3 == c2)	ball++;

	if (strike == s && ball == b)
		return true;

	return false;
}

int main() {
	int n;
	cin >> n;

	memset(chk, 0, sizeof(chk));

	for (int i = 0; i < n; i++) {
		cin >> q >> s >> b;
		
		for (int i = 123; i <= 987; i++) {
			if (!check(i))
				chk[i] = 1;
		}		
	}

	int cnt = 0;
	for (int i = 123; i <= 987; i++) {
		if (chk[i] == 0)
			cnt++;
	}
	cout << cnt << '\n';

	return 0;
}