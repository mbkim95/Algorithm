#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str) {
	stack<char> s;
	for (char c : str) {
		if (c == '(') s.push(c);
		else {
			if (s.empty()) return false;
			s.pop();
		}
	}
	if (!s.empty()) return false;
	return true;
}

pair<string, string> cutUV(string str) {
	int cnt = 0;
	int idx = 0;
	for (char c : str) {
		idx++;
		if (c == '(') cnt++;
		else cnt--;
		if (cnt == 0) break;
	}
	return { str.substr(0, idx), str.substr(idx, str.length() - idx) };
}

string solution(string p) {
	string answer = p;
	if (isCorrect(answer)) return answer;
	pair<string, string> s = cutUV(answer);
	string u = s.first;
	string v = s.second;
	if (isCorrect(u)) {
		answer = u + solution(v);
	}
	else {
		answer = "(" + solution(v) + ")";
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			char c = u[i];
			if (c == '(') u[i] = ')';
			else u[i] = '(';
		}
		answer += u;
	}
	return answer;
}