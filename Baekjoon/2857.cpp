#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> ans;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		if (s.find("FBI") != string::npos) {
			ans.push_back(i);
		}
	}
	if (ans.size() == 0) cout << "HE GOT AWAY!\n";
	else {
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}