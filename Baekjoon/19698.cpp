#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, w, h, l;
	cin >> n >> w >> h >> l;

	int w_max = w / l;
	int h_max = h / l;

	cout << min(n, w_max * h_max) << '\n';	
	return 0;
}