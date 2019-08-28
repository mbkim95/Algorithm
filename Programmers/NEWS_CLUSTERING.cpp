#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool inRange(char ch) {
	return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

void changeString(string& str) {
	int diff = 'A' - 'a';
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] += diff;
	}
}

int solution(string str1, string str2) {
	vector<string> s1, s2, s3;
	changeString(str1);
	changeString(str2);
	for (int i = 0; i < str1.length() - 1; i++) {
		string tmp = str1.substr(i, 2);
		if (inRange(tmp[0]) && inRange(tmp[1]))
			s1.push_back(tmp);
	}

	for (int i = 0; i < str2.length() - 1; i++) {
		string tmp = str2.substr(i, 2);
		if (inRange(tmp[0]) && inRange(tmp[1]))
			s2.push_back(tmp);
	}

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s2[j] == " ") continue;
			if (s1[i] == s2[j]) {
				s3.push_back(s1[i]);
				s2[j] = " ";
				break;
			}
		}
	}
	int u = s1.size() + s2.size() - s3.size();
	int n = s3.size();
	float value;
	if (u == 0)
		value = 1;
	else
		value = (float)n / u;
	int answer = value * 65536;
	return answer;
}

int main() {
	string str1, str2;
	str1 = "aa1+aa2";
	str2 = "AAAA12";
	cout << solution(str1, str2) << '\n';
	return 0;
}