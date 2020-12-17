#include <iostream>
using namespace std;

int a[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a_score = 0, b_score = 0;
	for (int i = 0; i < 10; i++)
		cin >> a[i];

	int b, last_win = 0;
	for (int i = 0; i < 10; i++) {
		cin >> b;
		if (a[i] < b) {
			b_score += 3;
			last_win = 2;
		}
		else if (a[i] > b) {
			a_score += 3;
			last_win = 1;
		}
		else {
			a_score++;
			b_score++;
		}
	}
	cout << a_score << ' ' << b_score << '\n';
	if (a_score > b_score || last_win == 1) cout << "A\n";
	else if (a_score < b_score || last_win == 2) cout << "B\n";
	else cout << "D\n";
	return 0;
}