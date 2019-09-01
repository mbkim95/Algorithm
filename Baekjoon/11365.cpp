#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str = "";
	vector<string> v;
	while (true) {
		getline(cin, str);
		if (str == "END") break;
		reverse(str.begin(), str.end());
		v.push_back(str);
	}
	for(int i=0; i<v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}