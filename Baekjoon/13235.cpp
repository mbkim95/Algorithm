#include <iostream>
using namespace std;

bool isSymmetry(string str) {
	int length = str.length();
		
	if (length < 2) return true;

	string temp1, temp2;
	if (length % 2 == 1) {
		temp1 = str.substr(0, length / 2);
		temp2 = str.substr(length / 2 + 1, length / 2);
	}
	else {
		temp1 = str.substr(0, length / 2);
		temp2 = str.substr(length / 2, length / 2);
	}

	for (int i = 0; i < length / 2; i++) {
		if (temp1[i] != temp2[temp2.length() - 1 - i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	if (isSymmetry(str)) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}
	return 0;
}