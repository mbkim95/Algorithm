#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int count_bits(int n) {
	int ret = 0;
	while (n) {
		if ((n & 1) == 1)  ret++;
		n >>= 1;
	}
	return ret;
}

bool cmp(int n1, int n2) {
	int x = count_bits(n1), y = count_bits(n2);
	return x > y;
}

int check(vector<vector<string>>& relation, int row_size, int col_size, int subset) {
	for (int i = 0; i < row_size - 1; i++) {
		for (int j = i + 1; j < row_size; j++) {
			bool is_same = true;
			for (int k = 0; k < col_size; k++) {
				if ((subset & 1 << k) == 0) continue;
				if (relation[i][k] != relation[j][k]) {
					is_same = false;
					break;
				}
			}
			if (is_same) return false;
		}
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int row_size = relation.size();
	int col_size = relation[0].size();
	vector<int> candidates;
	for (int i = 1; i < 1 << col_size; i++) {
		if (check(relation, row_size, col_size, i)) candidates.push_back(i);
	}

	sort(candidates.begin(), candidates.end(), cmp);
	
	while (!candidates.empty()) {
		int n = candidates.back();
		candidates.pop_back();
		answer++;
		for (auto it = candidates.begin(); it != candidates.end();) {
			if ((n & *it) == n) it = candidates.erase(it);
			else it++;
		}
	}
	return answer;
}