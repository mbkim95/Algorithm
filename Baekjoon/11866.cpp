#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
	return 0;
}
