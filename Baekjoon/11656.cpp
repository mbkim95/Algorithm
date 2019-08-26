#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string tmp;
	cin >> tmp;
	vector<string> str(tmp.length());
	for (int i = 0; i < tmp.length(); i++) {
		string temp = tmp.substr(i, tmp.length() - i);
		str[i] = temp;
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
		cout << str[i] << '\n';
	return 0;
}