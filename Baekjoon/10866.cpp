#include <iostream>
#include <deque>
#include <string>
using namespace std;

 	int n;
	cin >> n;
	deque<int> d;

	while (n--) {
		string s;
		cin >> s;
		if (s == "push_back") {
			int tmp;
			cin >> tmp;
			d.push_back(tmp);
		}
		else if (s == "push_front") {
			int tmp;
			cin >> tmp;
			d.push_front(tmp);
		}
		else if (s == "pop_front") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (s == "size") {
			cout << d.size() << '\n';
		}
		else if (s == "empty") {
			cout << d.empty() << '\n';
		}
		else if (s == "front") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		}
		else if (s == "back") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
	}
}