#include <string>
#include <vector>

using namespace std;

int one, zero;

void calculate(vector<vector<int>>& arr, int x, int y, int size) {
	if (size == 1) {
		if (arr[y][x] == 0) zero++;
		else one++;
		return;
	}

	int tmp = arr[y][x];
	bool is_same = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (tmp != arr[y + i][x + j]) {
				is_same = false;
			}
		}
		if (!is_same) break;
	}
	if (!is_same) {
		calculate(arr, x, y, size / 2);
		calculate(arr, x + size / 2, y, size / 2);
		calculate(arr, x, y + size / 2, size / 2);
		calculate(arr, x + size / 2, y + size / 2, size / 2);
	}
	else {
		if (tmp == 0) zero++;
		else one++;
	}
}

vector<int> solution(vector<vector<int>> arr) {
	calculate(arr, 0, 0, arr.size());
	vector<int> answer = { zero, one };
	return answer;
}