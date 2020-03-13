#include <iostream>
#include <string>
using namespace std;

string add(string num1, string num2) {
	string ret = "";
	string n1, n2;
	int diff = num1.length() - num2.length();
	if (diff >= 0) {
		n1 = num1;
		n2 = num2;
	}
	else {
		n1 = num2;
		n2 = num1;
	}
	for (int i = 0; i < abs(diff); i++) {
		ret += n1[i];
	}

	for (int i = 0; i < n2.length(); i++) {
		if (n1[i + diff] == '1' && n2[i] == '1')
			ret += '2';
		else if (n1[i + diff] == '1' || n2[i] == '1')
			ret += '1';
		else
			ret += '0';
	}
	return ret;
}

string mul(string num1, string num2) {
	string ret = "1";
	int len = num1.length() + num2.length() - 2;
	for (int i = 0; i < len; i++)
		ret += "0";
	return ret;
}

int main() {
	string num1, num2;
	char op;
	cin >> num1;
	cin >> op;
	cin >> num2;

	if (op == '+')
		cout << add(num1, num2) << '\n';
	else
		cout << mul(num1, num2) << '\n';
	return 0;
}