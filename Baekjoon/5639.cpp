#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> tree;

void postOrder(int start, int end) {
	if (start == end) return;

	if (start == end - 1) {
		printf("%d\n", tree[start]);
		return;
	}

	int idx = start + 1;

	while (true) {
		if (idx >= end || tree[idx] > tree[start]) break;
		idx++;
	}
	postOrder(start + 1, idx);
	postOrder(idx, end);
	printf("%d\n", tree[start]);
}

int main() {
	int temp;

	while (scanf("%d", &temp) == 1) {
		tree.push_back(temp);
		n++;
	}
	postOrder(0, n);
	return 0;
}