#include <string>
#include <set>
using namespace std;

bool inRange(int x, int y) {
	return (-5 <= x && x <= 5) && (-5 <= y && y <= 5);
}

int solution(string dirs) {
	int answer = 0;
	set<pair<pair<int, int>, pair<int, int>>> s;
	int x = 0;
	int y = 0;
	for (char c : dirs) {
		if (c == 'U') {
			if (inRange(x, y + 1)) {
				if (s.find({ {x, y}, {x, y + 1} }) == s.end()) {
					answer++;
					s.insert({ {x, y}, {x, y + 1} });
					s.insert({ {x, y + 1}, {x, y} });
				}
				y++;
			}
		}
		else if (c == 'L') {
			if (inRange(x - 1, y)) {
				if (s.find({ {x, y}, {x - 1, y} }) == s.end()) {
					answer++;
					s.insert({ {x, y}, {x - 1, y} });
					s.insert({ {x - 1, y}, {x, y} });
				}
				x--;
			}
		}
		else if (c == 'R') {
			if (inRange(x + 1, y)) {
				if (s.find({ {x, y}, {x + 1, y} }) == s.end()) {
					answer++;
					s.insert({ {x, y}, {x + 1, y} });
					s.insert({ {x + 1, y} , {x, y} });
				}
				x++;
			}
		}
		else if (c == 'D') {
			if (inRange(x, y - 1)) {
				if (s.find({ {x, y}, {x, y - 1} }) == s.end()) {
					answer++;
					s.insert({ {x, y}, {x, y - 1} });
					s.insert({ {x, y - 1}, {x, y} });
				}
				y--;
			}
		}
	}
	return answer;
}