#include <iostream>
using namespace std;

int n;
int h[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	int cnt = 1;
	int pivot = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (h[i] > pivot) {
			cnt++;
			pivot = h[i];
		}
	}
	cout << cnt << '\n';
	return 0;
}