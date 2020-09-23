#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2;
	cin >> n1 >> n2;
	vector<int> a(n1);
	set<int> b;
	for (int i = 0; i < n1; i++)
		cin >> a[i];
	for (int i = 0; i < n2; i++) {
		int tmp;
		cin >> tmp;
		b.insert(tmp);
	}
	vector<int> answer;
	for (int num : a) {
		if (b.find(num) == b.end())
			answer.push_back(num);
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i : answer)
		cout << i << ' ';
	return 0;
}