#include <iostream>
#include <algorithm>
using namespace std;

int tri[45] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861, 903, 946, 990};

bool isEureka(int num) {
	for (int i = 1; i <= 44; i++) {
		for (int j = 1; j <= 44; j++) {
			for (int k = 1; k <= 44; k++) {
				if (tri[i] + tri[j] + tri[k] == num)
					return true;
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;

		cout << isEureka(num	) << '\n';
	}

	return 0;	
}