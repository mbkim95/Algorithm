#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string cmd;
		int n;
		string num;
		deque<int> q;
		cin >> cmd;
		cin >> n;
		cin >> num;

		string tmp;
		for (int i = 0; i < num.length(); i++) {
			if (num[i] == '[') continue;
			else if ('0' <= num[i] && num[i] <= '9') {
				tmp += num[i];
			}
			else {
				if (!tmp.empty()) {
					q.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}

		bool r = false;
		bool err = false;

		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R') {
				r = !r;
			}
			else if (cmd[i] == 'D') {
				if (q.empty()) {
					err = true;
					break;
				}
				if (r == true)
					q.pop_back();
				else
					q.pop_front();
			}
		}

		if (err) {
			cout << "error\n";
			continue;
		}
		cout << '[';
		if (r == true) {
			while (!q.empty()) {
				cout << q.back();
				q.pop_back();
				if (q.size() != 0)
					cout << ',';
			}
		}
		else {
			while (!q.empty()) {
				cout << q.front();
				q.pop_front();
				if (q.size() != 0)
					cout << ',';
			}
		}
		cout << "]\n";
	}
	return 0;
}