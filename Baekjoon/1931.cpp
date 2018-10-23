#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time {
	int s, e;
};

bool cmpTime(const Time &a, const Time &b) {
	if (a.e == b.e)
		return a.s < b.s;
	return a.e < b.e;
}

int main() {
	vector<Time> v;
	Time t;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t.s >> t.e;
		v.push_back(t);
	}
	
	sort(v.begin(), v.end() , cmpTime);

	int end = 0, cnt = 0;;

	for (int i = 0; i < n; i++) {
		if (end <= v[i].s) {
			end = v[i].e;
			cnt++;
		}
	}
	cout << cnt << endl;
}