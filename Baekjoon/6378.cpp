#include <iostream>
#include <string>
using namespace std;

string calc(string num) {
	string ret = "";

	while (true) {
		ret = "";
		int tmp = 0;
		for (int i = 0; i < num.size(); i++) {
			tmp += (num[i] - '0');
		}
		ret += to_string(tmp);
		if (ret.size() == 1)
			break;
		num = ret;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		string n;
		cin >> n;
		if (n == "0") break;
		cout << calc(n) << '\n';
	}
	return 0;
}