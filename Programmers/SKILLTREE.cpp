#include <iostream>
#include <string>
#include <vector>
using namespace std;

void precalc(vector<int>& chk, string skill) {
	int order = 1;
	for (int i = 0; i<skill.length(); i++) {
		int idx = skill[i] - 'A';
		chk[idx] = order++;
	}
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<int> chk(26, 0);
	precalc(chk, skill);
	for (int i = 0; i<skill_trees.size(); i++) {
		string str = skill_trees[i];
		int order = 1;
		int skill_order = 0;
		bool find = false;
		for (int j = 0; j<str.length(); j++) {
			if (chk[str[j] - 'A'] == 0)
				continue;
			if (order > chk[str[j] - 'A']) {
				find = true;
				break;
			}
			else {
				skill_order++;
				order = chk[str[j] - 'A'];
				if (order != skill_order) {
					find = true;
					break;
				}
			}
		}
		if (!find)
			answer++;
	}
	return answer;
}

int main() {
	string skill = "CBD";
	vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
	cout << solution(skill, skill_trees) << '\n';
	return 0;
}