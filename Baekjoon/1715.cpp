#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		int sum = n1 + n2;
		ans += sum;
		pq.push(sum);
	}
	cout << ans << '\n';
	return 0;
}