#include <string>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& key) {
	vector<vector<int>> tmp = key;
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < key[i].size(); j++) {
			key[i][j] = tmp[key.size() - 1 - j][i];
		}
	}
}

bool isRight(int n, vector<vector<int>>& lock) {
	for (int i = n; i < 2 * n; i++)
		for (int j = n; j < 2 * n; j++)
			if (lock[i][j] != 1) return false;
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	vector<vector<int>> big_lock(lock.size() * 3, vector<int>(lock.size() * 3, 0));
	int n = lock.size();
	int m = key.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			big_lock[n + i][n + j] = lock[i][j];
		}
	}
	for (int r = 0; r < 4; r++) {
		rotate(key);
		int idx1 = 0;
		for (int a = n - m + 1; a < 2 * n; a++) {
			for (int b = n - m + 1; b < 2 * n; b++) {
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						big_lock[a + i][b + j] += key[i][j];
					}
				}
				if (isRight(n, big_lock)) return true;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						big_lock[a + i][b + j] -= key[i][j];
					}
				}
			}
		}
	}
	return answer;
}