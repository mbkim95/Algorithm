#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	int s, e, m;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> m;
		rotate(v.begin() + s - 1, v.begin() + m - 1, v.begin() + e);
	}
	for (auto &x : v)
		cout << x << ' ';
	cout << '\n';
	return 0;
}