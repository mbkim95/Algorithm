#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		stack<char> result;
		stack<char> temp;

		for (int i = 0; i < str.length(); i++) {
			char current = str[i];

			if (current == '<') {
				if (!result.empty()) {
					temp.push(result.top());
					result.pop();
				}
			}
			else if (current == '>') {
				if (!temp.empty()) {
					result.push(temp.top());
					temp.pop();
				}
			}
			else if (current == '-') {
				if(!result.empty())
					result.pop();
			}
			else {
				result.push(current);
			}
		}
		while (!temp.empty()) {
			result.push(temp.top());
			temp.pop();
		}
		string answer;

		while (!result.empty()) {
			answer += result.top();
			result.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer << '\n';
	}
	return 0;
}