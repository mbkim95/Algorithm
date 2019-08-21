#include <iostream>
using namespace std;

int n;
int inOrder[100001], postOrder[100001], index[100001];

void preOrder(int inStart, int inEnd, int postStart, int postEnd){
        if (inStart> inEnd || postStart > postEnd)
			return;

        int root = postOrder[postEnd];
        cout << root << " ";
		preOrder(inStart, index[root] - 1, postStart, postStart + (index[root] - inStart) - 1);
		preOrder(index[root] + 1, inEnd, postStart + (index[root] - inStart), postEnd - 1);
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inOrder[i];

	for (int i = 0; i < n; i++)
		cin >> postOrder[i];
	for (int i = 0; i < n; i++)
		index[inOrder[i]] = i;
	preOrder(0, n - 1, 0, n - 1);
	cout << "\n";
	return 0;
}