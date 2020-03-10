#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<char, int> team;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		team[temp[0]]++;
	}

	vector<char> ans;
	for (map<char, int>::iterator it = team.begin(); it != team.end(); it++) {
		if (it->second >= 5)
			ans.push_back(it->first);
	}
	if (ans.size() == 0) {
		cout << "PREDAJA" << '\n';
	}
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << '\n';
	}
	return 0;
}