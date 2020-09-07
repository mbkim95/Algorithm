#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i<commands.size(); i++) {
		vector<int> tmp = array;
		int a = commands[i][0];
		int b = commands[i][1];
		int c = commands[i][2];
		sort(tmp.begin() + a - 1, tmp.begin() + b);
		answer.push_back(*(tmp.begin() + a + c - 2));
	}
	return answer;
}