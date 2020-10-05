#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 0;
	while (n--) {
		string s;
		cin >> s;
		stack<char> st;
		for (char c : s) {
			if (st.empty() || st.top() != c) st.push(c);
			else st.pop();
		}
		if (st.empty()) answer++;
	}
	cout << answer << '\n';
	return 0;
}