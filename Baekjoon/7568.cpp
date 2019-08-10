#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> w, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	w = vector<int>(n);
	h = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
	}

	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (w[i] < w[j] && h[i] < h[j])
				cnt++;
		}
		cout << cnt << ' ';
	}
	cout << '\n';
	return 0;
}