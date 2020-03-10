#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string in;
		list<char> pw;
		cin >> in;
		list<char>::iterator it = pw.begin();

		for (int i = 0; i < in.size(); i++) {
			char cur = in[i];
			if (cur == '<') {
				if (it != pw.begin())
					it--;
			}
			else if (cur == '>') {
				if (it != pw.end())
					it++;
			}
			else if (cur == '-') {
				if (it != pw.begin()) {
					it = pw.erase(--it);
				}
			}
			else {
				pw.insert(it, cur);
			}
		}
		for (auto p : pw)
			cout << p;
		cout << '\n';
	}
	return 0;
}