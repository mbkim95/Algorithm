#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> s1(2), s2(2);
	cin >> s1[0] >> s2[0];
	s1[1] = s1[0];
	s2[1] = s2[0];
	for (int i = 0; i < s1[0].length(); i++) {
		if (s1[0][i] == '5') {
			s1[1][i] = '6';
		}
		else if (s1[0][i] == '6') {
			s1[1][i] = '6';
			s1[0][i] = '5';
		}
	}
	for (int i = 0; i < s2[0].length(); i++) {
		if (s2[0][i] == '5') {
			s2[1][i] = '6';
		}
		else if (s2[0][i] == '6') {
			s2[1][i] = '6';
			s2[0][i] = '5';
		}
	}
	cout << stoi(s1[0]) + stoi(s2[0]) << ' ' << stoi(s1[1]) + stoi(s2[1]) << '\n';
	return 0;
}