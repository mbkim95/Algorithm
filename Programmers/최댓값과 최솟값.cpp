#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parseString(string s) {
	vector<int> ret;
	bool find = true;
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == ' ') {
			string tmp = s.substr(idx, i - idx);
			ret.push_back(stoi(tmp));
			find = false;
			idx = i + 1;
		}
		else {
			find = true;
		}
	}
	if (find) {
		string tmp = s.substr(idx, s.length() - idx);
		ret.push_back(stoi(tmp));
	}
	return ret;
}

string solution(string s) {
	string answer = "";
	vector<int> num = parseString(s);
	sort(num.begin(), num.end());
	answer += (to_string(num[0]) + " " + to_string(num[num.size() - 1]));
	return answer;
}