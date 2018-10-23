#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b){
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int> preorder, const vector<int> inorder) {
	const int N = preorder.size();

	if (preorder.empty())
		return;

	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - 1 - L;

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << ' ';
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i<n; i++)
			cin >> preorder[i];
		for (int i = 0; i<n; i++)
			cin >> inorder[i];
		printPostOrder(preorder, inorder);
		cout << '\n';
	}
	return 0;
}