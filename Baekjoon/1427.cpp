#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<char> v;
	for (int i = 0; i < str.size(); i++) {
		char tmp = str.at(i);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), greater<int>());
	
	for (auto x : v)
		cout << x;
	cout << '\n';
}