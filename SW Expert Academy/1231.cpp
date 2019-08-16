#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<char> tree;

void inOrder(int parent) {
	int left = 2 * parent;
	int right = 2 * parent + 1;
	if (left <= n) {
		inOrder(left);
	}
	cout << tree[parent];
	if (right <= n) {
		inOrder(right);
	}
}

int main() {
	for (int c = 1; c <= 10; c++) {
		cin >> n;
		tree = vector<char>(n+1);
		int parent, left, right;
		char value;
		for (int i = 0; i < floor(n / 2) - 1; i++) {
			cin >> parent >> value >> left >> right;
			tree[parent] = value;
		}
		if (n % 2 == 1) {
			cin >> parent >> value >> left >> right;
			tree[parent] = value;
		}
		else {
			cin >> parent >> value >> left;
			tree[parent] = value;
		}
		for (int i = floor(n / 2) + 1; i <= n; i++) {
			cin >> parent >> value;
			tree[parent] = value;
		}
		cout << "#" << c << ' ';
		inOrder(1);
		cout << '\n';
	}
	return 0;
}