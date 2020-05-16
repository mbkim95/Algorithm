#include <iostream>
using namespace std;

int main() {
	int s = 0, t = 0;
	int tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		s += tmp;
	}
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		t += tmp;
	}
	if (s >= t) cout << s << '\n';
	else cout << t << '\n';
	return 0;
}