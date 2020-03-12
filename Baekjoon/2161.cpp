#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n;
	cin >> n;

	deque<int> card;

	for (int i = 1; i <= n; i++) {
		card.push_back(i);
	}

	while (!card.empty()) {
		int front = card.front();
		card.pop_front();
		cout << front << ' ';
		if (card.empty())
			break;
		card.push_back(card.front());
		card.pop_front();
	}
	cout << '\n';
	return 0;
}