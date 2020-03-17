#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int s = 0;
	while (n--) {
		string cmd;
		int num;
		cin >> cmd;

		if (cmd == "add") {
			cin >> num;
			s |= (1 << num);
		}
		else if (cmd == "remove") {
			cin >> num;
			s &= ~(1 << num);
		}
		else if (cmd == "check") {
			cin >> num;
			if (s & (1 << num)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "toggle") {
			cin >> num;
			s ^= (1 << num);
		}
		else if (cmd == "all") {
			s = (1 << 21) - 1;
		}
		else if (cmd == "empty") {
			s = 0;
		}
	}
}