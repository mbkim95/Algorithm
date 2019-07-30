#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n;
long long c;
map<int, long long> t;

long long insert(int num) {
	map<int, long long>::iterator lb = --t.lower_bound(num);
	map<int, long long>::iterator ub = t.upper_bound(num);
	long long depth = max(lb->second, ub->second) + 1;
	t.insert(pair<int, long long>(num, depth));
	return depth;
}

int main(void) {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	t.insert(pair<int, long long>(0, -1));
	t.insert(pair<int, long long>(300001, -1));

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;		
		c += insert(tmp);
		cout << c << '\n';
	}
	return 0;
}