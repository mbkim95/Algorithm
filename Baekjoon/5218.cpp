#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.length();
		cout << "Distances: ";
		for (int i = 0; i < len; i++) {
			char a = s1[i];
			char b = s2[i];
			int diff;
			if (a <= b) diff = b - a;
			else diff = b - a + 26;
			cout << diff << ' ';
		}
		cout << '\n';
	}
}