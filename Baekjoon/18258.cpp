#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	deque<int> q;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (cmd == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
		else if (cmd == "size")
			cout << q.size() << '\n';
		else if (cmd == "empty")
			cout << q.empty() << '\n';
		else if (cmd == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else {
			int num;
			cin >> num;
			q.push_back(num);
		}
	}
	return 0;
}