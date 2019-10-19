#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> num, tmp;
vector<char> op;
vector<bool> chk;

void dfs(int idx) {
	if (idx == chk.size()) {
		int sum = tmp[0];
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == '+') sum += tmp[i + 1];
			if (op[i] == '-') sum -= tmp[i + 1];
			if (op[i] == '*') sum *= tmp[i + 1];
		}	
		ans = max(ans, sum);
		return;
	}
	if (!chk[idx - 1]) {
		chk[idx] = true;
		if (op[idx] == '+') {
			tmp[idx] = num[idx] + num[idx + 1];
			tmp[idx + 1] = 0;
		}
		if (op[idx] == '-') {
			tmp[idx] = num[idx] - num[idx + 1];
			tmp[idx + 1] = 0;
		}
		if (op[idx] == '*') {
			tmp[idx] = num[idx] * num[idx + 1];
			tmp[idx + 1] = 1;
		}
		dfs(idx + 1);
		chk[idx] = false;
		tmp[idx] = num[idx];
		tmp[idx + 1] = num[idx + 1];
	}
	dfs(idx + 1);
}

int main() {
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (i % 2 == 0) num.push_back(str[i] - '0');
		else op.push_back(str[i]);
	}
	tmp = num;
	chk = vector<bool>(op.size(), false);
	if (str.size() != 1) {
		ans = num[0];
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == '+') ans += num[i + 1];
			if (op[i] == '-') ans -= num[i + 1];
			if (op[i] == '*') ans *= num[i + 1];
		}
		chk[0] = true;
		if (op[0] == '+') {
			tmp[0] = num[0] + num[1];
			tmp[1] = 0;
		}
		if (op[0] == '-') {
			tmp[0] = num[0] - num[1];
			tmp[1] = 0;
		}
		if (op[0] == '*') {
			tmp[0] = num[0] * num[1];
			tmp[1] = 1;
		}
		dfs(1);
		chk[0] = false;
		tmp[0] = num[0];
		tmp[1] = num[1];
		dfs(1);
	}
	else ans = num[0];
	cout << ans << '\n';
	return 0;
}