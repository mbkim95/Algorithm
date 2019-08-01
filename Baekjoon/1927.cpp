#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (q.empty())
				cout << "0\n";
			else {
				tmp = -q.top();
				q.pop();
				cout << tmp << '\n';
			}
		}
		else {
			q.push(-tmp);
		}
	}
	return 0;
}