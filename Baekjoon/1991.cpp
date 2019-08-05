#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, size;
vector<char> tree;

int findNode(char value){
	for (int i = 0; i <= size; i++) {
		if (tree[i] == value)
			return i;
	}
	return -1;
}

void insertNode(char value, char left, char right) {
	int idx = findNode(value);
	if (left != '.') {
		tree[2 * idx + 1] = left;
		size = max(size, 2 * idx + 1);
	}
	if (right != '.') {
		tree[2 * idx + 2] = right;
		size = max(size, 2 * idx + 2);
	}
}

void preOrder(int idx) {
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	cout << tree[idx];
	if (tree[left] != '.')
		preOrder(left);
	if (tree[right] != '.')
		preOrder(right);	
}

void inOrder(int idx) {
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	if (tree[left] != '.')
		inOrder(left);
	cout << tree[idx];
	if (tree[right] != '.')
		inOrder(right);
}

void postOrder(int idx) {
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	if (tree[left] != '.')
		postOrder(left);
	if (tree[right] != '.')
		postOrder(right);
	cout << tree[idx];
}

void solve() {
	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
	cout << '\n';
}

int main() {
	cin >> n;
	tree = vector<char>(pow(2, 26) - 1, '.');
	tree[0] = 'A';
	size++;
	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		insertNode(root, left, right);
	}
	solve();
	return 0;
}