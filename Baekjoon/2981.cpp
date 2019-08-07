#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

int gcd(int p, int q) {
	if (q == 0) 
		return p;
	return gcd(q, p % q);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int g = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		g = gcd(g, v[i] - v[i - 1]);
	}
	vector<int> ans;
	for (int i = 2; i*i <= g; i++) {
		if (g % i == 0) {
			ans.push_back(i);
			if (i != g / i)
				ans.push_back(g / i);
		}
	}
	ans.push_back(g);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}