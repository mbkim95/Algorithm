#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	string str, src;
	getline(cin, str);
	getline(cin, src);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == src[0]) {
			int j;
			bool find = true;
			for (j = 0; j < src.length(); j++) {
				if (str[i + j] != src[j]) {
					find = false;
					break;
				}
			}
			if (find) {
				i += j - 1;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}