#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		int score = 0, total = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str.at(i) == 'O') {
				score++;
				total += score;
			}
			else {
				score = 0;
			}
		}
		cout << total << '\n';
	}
	return 0;
}