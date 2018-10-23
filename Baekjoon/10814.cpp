#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
	int age;
	string name;
};

int main() {
	int n;
	cin >> n;
	vector<Person> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;

	}
	
	stable_sort(v.begin(), v.end(), [](Person a, Person b) {
		return a.age < b.age;
	});

	for (auto x : v)
		cout << x.age << ' ' << x.name << '\n';
	return 0;
}