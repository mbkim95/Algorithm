#include <string>
#include <vector>
#include<set>
using namespace std;

bool visited[10];
set<string> ans;

void dfs(vector<string>& user_id, vector<string>& banned_id, int idx) {
	if (idx == banned_id.size()) {
		string res = "";
		for (int i = 0; i < user_id.size(); i++) {
			if (visited[i]) {
				res += i;
			}
		}
		ans.insert(res);
		return;
	}

	for (int i = 0; i < user_id.size(); i++) {
		if (banned_id[idx].size() != user_id[i].size() || visited[i])  continue;

		bool find = true;
		for (int j = 0; j < user_id[i].size(); j++) {
			if (banned_id[idx][j] == '*') continue;
			if (banned_id[idx][j] != user_id[i][j]) {
				find = false;
				break;
			}
		}

		if (find) {
			visited[i] = true;
			dfs(user_id, banned_id, idx + 1);
			visited[i] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	dfs(user_id, banned_id, 0);
	int answer = ans.size();
	return answer;
}