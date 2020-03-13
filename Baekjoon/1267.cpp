#include <iostream>
using namespace std;

int main() {
	int n;
	int yungsik = 0;
	int minsik = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time;
		cin >> time;

		yungsik += (time / 30 + 1) * 10;
		minsik += (time / 60 + 1) * 15;
	}
	if (yungsik == minsik)
		cout << "Y M " << minsik << '\n';
	else if (yungsik < minsik)
		cout << "Y " << yungsik << '\n';
	else
		cout << "M " << minsik << '\n';
	return 0;
}