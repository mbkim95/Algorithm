#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	priority_queue<int> pq;

	cin >> n;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			pq.push(-tmp);
			if (pq.size() > n) pq.pop();
		}
	}
	cout << -pq.top() << '\n';
	return 0;
}