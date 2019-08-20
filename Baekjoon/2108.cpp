#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> num;
vector<int>cnt;
vector<int> list;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cnt = vector<int>(8001, 0);
	int sum = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		num.push_back(tmp);
		if (tmp == 0)
			zero++;
		else
			cnt[tmp+4000]++;
	}
	sort(num.begin(), num.end());
	int c = zero;
	list.push_back(0);
	for (int i = 0; i <= 8000; i++) {
		if (c == cnt[i]) {
			list.push_back(i - 4000);
		}
		else if (c < cnt[i]) {
			list.clear();
			list.push_back(i - 4000);
			c = cnt[i];
		}
	}
	sort(list.begin(), list.end());
	cout << floor(((float)sum / n) + 0.5) << '\n' << num[n / 2] << '\n';
	if (list.size() == 1)
		cout << list[0] << '\n';
	else
		cout << list[1] << '\n';
	cout << num[num.size() - 1] - num[0] << '\n';
	return 0;
}#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> num;
vector<int>cnt;
vector<int> list;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cnt = vector<int>(8001, 0);
	int sum = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		num.push_back(tmp);
		if (tmp == 0)
			zero++;
		else
			cnt[tmp+4000]++;
	}
	sort(num.begin(), num.end());
	int c = zero;
	list.push_back(0);
	for (int i = 0; i <= 8000; i++) {
		if (c == cnt[i]) {
			list.push_back(i - 4000);
		}
		else if (c < cnt[i]) {
			list.clear();
			list.push_back(i - 4000);
			c = cnt[i];
		}
	}
	sort(list.begin(), list.end());
	cout << floor(((float)sum / n) + 0.5) << '\n' << num[n / 2] << '\n';
	if (list.size() == 1)
		cout << list[0] << '\n';
	else
		cout << list[1] << '\n';
	cout << num[num.size() - 1] - num[0] << '\n';
	return 0;
}