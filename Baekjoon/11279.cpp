#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int x;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (q.empty())
				cout << 0 << '\n';
			else {
				x = q.top();
				q.pop();
				cout << x << '\n';
			}
		}
		else
			q.push(x);
	}
	return 0;
}