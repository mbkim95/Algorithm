#include <iostream>
using namespace std;

int  main() {
	string str, ans;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		for (int j = 0; j < 3; j++) {
			ch--;
			if (ch < 'A')
				ch = 'Z';
		}
		ans.push_back(ch);
	}
	cout << ans << '\n';
	return 0;
}