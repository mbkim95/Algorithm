#include <iostream>
#include <string>
using namespace std;

string str;

int checkAnswer(string tmp){
	if (tmp == "c=" || tmp == "c-" || tmp == "d-" || tmp == "s=" || tmp == "z=" || tmp == "dz=" || tmp == "lj" || tmp == "nj")
		return 1;
	return 0;
}

int solve() {
	int ans = 0;
	for (int i = 0; i < str.length(); ) {
		bool find = false;
		for (int j = 2; j <= 3; j++) {
			string tmp = str.substr(i, j);
			find = checkAnswer(tmp);
			if (find) {
				if (j == 2)
					i += 2;
				else
					i += 3;
				ans += 1;
				break;
			}
		}
		if (!find) {
			ans++;
			i++;
		}
	}
	return ans;
}

int main() {
	cin >> str;
	cout << solve() << '\n';
	return 0;
}