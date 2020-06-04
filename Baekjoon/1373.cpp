#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int pow(int num, int p) {
	int ret = 1;
	for (int i = 0; i < p; i++)
		ret *= num;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string bin, oct = "";
	cin >> bin;
	while (bin.length() % 3 != 0) bin = '0' + bin;
	for (int i = 0; i < bin.length(); i += 3) {
		string tmp = bin.substr(i, 3);
		int num = 0;
		for (int j = 0; j < 3; j++)
			if (tmp[j] == '1')
				num += pow(2, 2 - j);
		oct += to_string(num);
	}
	cout << oct << '\n';
	return 0;
}