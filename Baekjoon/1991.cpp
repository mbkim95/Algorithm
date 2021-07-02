#include <iostream>
#include <vector>
using namespace std;

int n;
vector<char> node[26];

void pre_order(int cur) {
	cout << (char) (cur + 'A');
	if(node[cur].size() > 0) {
		if(node[cur][0] != '.') pre_order(node[cur][0] - 'A');
		if(node[cur][1] != '.') pre_order(node[cur][1] - 'A');
	}
}

void in_order(int cur) {
	if(node[cur].size() > 0 && node[cur][0] != '.') in_order(node[cur][0] - 'A');
	cout << (char) (cur + 'A');
	if(node[cur].size() > 0 && node[cur][1] != '.') in_order(node[cur][1] - 'A');
}

void post_order(int cur) {
	if(node[cur].size() > 0 && node[cur][0] != '.') post_order(node[cur][0] - 'A');
	if(node[cur].size() > 0 && node[cur][1] != '.') post_order(node[cur][1] - 'A');
	cout << (char) (cur + 'A');
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		node[a - 'A'].push_back(b);
		node[a - 'A'].push_back(c);
	}
	pre_order(0);
	cout << '\n';
	in_order(0);
	cout << '\n';
	post_order(0);
	cout << '\n';
}