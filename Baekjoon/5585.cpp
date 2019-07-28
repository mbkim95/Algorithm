#include <iostream>
using namespace std;

const int coin[] = { 500, 100, 50, 10, 5, 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int money, cnt = 0, idx = 0;
	cin >> money;
	money = 1000 - money;
	while (money > 0) {
		if (money >= coin[idx]) {
			money -= coin[idx];
			cnt++;
		}
		else
			idx++;
	}
	cout << cnt << '\n';
	return 0;
}