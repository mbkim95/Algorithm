#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int hp, mp, attack, defence, hp_plus, mp_plus, attack_plus, defence_plus;
		cin >> hp >> mp >> attack >> defence >> hp_plus >> mp_plus >> attack_plus >> defence_plus;
		int h = hp + hp_plus;
		int m = mp + mp_plus;
		int a = attack + attack_plus;
		int d = defence + defence_plus;
		if (h < 1) h = 1;
		if (m < 1) m = 1;
		if (a < 0) a = 0;
		cout << h + (5 * m) + (2 * a) + (2 * d) << '\n';
	}
	return 0;
}