#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	int n = arr1.size(), m = arr2[0].size();
	vector<vector<int>> answer(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = 0; k < arr1[i].size(); k++) {
				sum += (arr1[i][k] * arr2[k][j]);
			}
			answer[i][j] = sum;
		}
	}
	return answer;
}