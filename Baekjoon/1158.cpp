#include <iostream>
#include <queue>
using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);
	
	cout << '<';
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (i != n)
			cout << ", ";
	}
	cout << '>' << '\n';

	return 0;
}