#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (min_heap.size() == max_heap.size()) {
			if (max_heap.size() == 0) {
				max_heap.push(tmp);
			}
			else {
				if (min_heap.top() >= tmp)
					max_heap.push(tmp);
				else {
					max_heap.push(min_heap.top());
					min_heap.pop();
					min_heap.push(tmp);
				}
			}
		}
		else {
			if (max_heap.size() > min_heap.size()) {
				if (max_heap.top() > tmp) {
					min_heap.push(max_heap.top());
					max_heap.pop();
					max_heap.push(tmp);
				}
				else {
					min_heap.push(tmp);
				}
			}
			else if (max_heap.size() < min_heap.size()) {
				if (min_heap.top() < tmp) {
					max_heap.push(min_heap.top());
					min_heap.pop();
					min_heap.push(tmp);
				}
				else {
					max_heap.push(tmp);
				}
			}
		}

		cout << max_heap.top() << '\n';
	}
	return 0;
}