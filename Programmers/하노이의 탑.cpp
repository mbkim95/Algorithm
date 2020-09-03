#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void hanoi(int n, int from, int to, int by) {
	if (n == 1) {
		ans.push_back({ from, to });
		return;
	}
	hanoi(n - 1, from, by, to);
	ans.push_back({ from, to });
	hanoi(n - 1, by, to, from);
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	hanoi(n, 1, 3, 2);
	answer = ans;
	return answer;
}