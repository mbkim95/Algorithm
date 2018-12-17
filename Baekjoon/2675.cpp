#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int r;
	string str;

	while (n--) {
		cin >> r >> str;

		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < r; j++) {
				cout << str[i];
			}
		}
		cout << endl;
	}
}