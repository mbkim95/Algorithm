#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long sum = 0;
	cin >> n;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		while (!s.empty() && s.top() <= tmp) s.pop();
		s.push(tmp);
		sum += s.size() - 1;
	}
	cout << sum << '\n';
	return 0;
}