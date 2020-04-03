#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	bool first = true;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (first && 'a' <= c && c <= 'z') {
			s[i] = c - ('a' - 'A');
			first = false;
		}
		else if (!first && 'A' <= c && c <= 'Z') {
			s[i] = c + ('a' - 'A');
		}
		else if (c == ' ') first = true;
		else first = false;
	}
	return s;
}