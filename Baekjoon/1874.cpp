#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	vector<int> num = vector<int>(n + 1);
	vector<char> result;
	bool possible = true;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (num[i] >= cnt) {
			while (num[i] != cnt) {
				result.push_back('+');
				s.push(cnt);
				cnt++;
			}
			result.push_back('+');
			result.push_back('-');
			cnt++;
		}
		else {
			while (!s.empty() && num[i] != s.top()) {
				result.push_back('-');
				s.pop();
			}

			if (s.empty()) {
				possible = false;
				break;
			}
			result.push_back('-');
			s.pop();
		}
	}

	if (possible) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
