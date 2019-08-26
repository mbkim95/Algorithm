#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, ans;
	cin >> str;
	for (int i = 0; i < str.length(); i++) 
		if ('A' <= str[i] && str[i] <= 'Z')
			ans.push_back(str[i]);
	cout << ans << '\n';
	return 0;
}