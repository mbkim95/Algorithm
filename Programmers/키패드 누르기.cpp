#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct pos {
	int x, y;
};

map<int, pos> l_hand = { {1, {0, 0}}, {4, {0, 1}} , {7, {0, 2}} };
map<int, pos> r_hand = { {3, {2, 0}}, {6, {2, 1}} , {9, {2, 2}} };
map<int, pos> mid_hand = { {2, {1, 0}}, {5, {1, 1}}, {8, {1, 2}}, {0, {1, 3}} };
pos l_pos = { 0, 3 }, r_pos = { 2, 3 };

int get_distance(pos p1, pos p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	for (int i : numbers) {
		if (l_hand.find(i) != l_hand.end()) {
			answer += "L";
			l_pos.x = l_hand[i].x;
			l_pos.y = l_hand[i].y;
		}
		else if (r_hand.find(i) != r_hand.end()) {
			answer += "R";
			r_pos.x = r_hand[i].x;
			r_pos.y = r_hand[i].y;
		}
		else {
			if (get_distance(l_pos, mid_hand[i]) > get_distance(r_pos, mid_hand[i])) {
				answer += 'R';
				r_pos.x = mid_hand[i].x;
				r_pos.y = mid_hand[i].y;
			}
			else if (get_distance(l_pos, mid_hand[i]) < get_distance(r_pos, mid_hand[i])) {
				answer += 'L';
				l_pos.x = mid_hand[i].x;
				l_pos.y = mid_hand[i].y;
			}
			else {
				if (hand == "right") {
					answer += 'R';
					r_pos.x = mid_hand[i].x;
					r_pos.y = mid_hand[i].y;
				}
				else {
					answer += 'L';
					l_pos.x = mid_hand[i].x;
					l_pos.y = mid_hand[i].y;
				}
			}
		}
	}
	return answer;
}