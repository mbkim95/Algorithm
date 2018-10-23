#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n;
	ios_base::sync_with_stdio(false);
	cin >> n;
	queue<int> q;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int tmp;
			cin >> tmp;
			q.push(tmp);
		}
		else if (s == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
}