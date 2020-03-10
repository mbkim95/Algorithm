#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> scores;

	for (int i = 1; i <= 8; i++) {
		int score;
		cin >> score;
		scores.push_back(make_pair(score, i));
	}

	sort(scores.begin(), scores.end(), greater<pair<int, int>>());

	vector<int> number;
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += scores[i].first;
		number.push_back(scores[i].second);
	}
	cout << total << '\n';
	sort(number.begin(), number.end());
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << ' ';
	}
	cout << '\n';
	return 0;
}