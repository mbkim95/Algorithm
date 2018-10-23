#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct Person {
	string name;
	int k, e, m;
};

bool cmp(Person a, Person b) {
	return make_tuple(-a.k, a.e, -a.m, a.name) < make_tuple(-b.k, b.e, -b.m, b.name);
}

int main() {
	int n;
	cin >> n;
	vector<Person> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].k >> v[i].e >> v[i].m;
	}
	sort(v.begin(), v.end(), cmp);

	for (auto x : v)
		cout << x.name << '\n';
	return 0;
}