#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<int> tmp(n);
	for (int i = 0; i < n; i++) 
		tmp[i] = arr1[i] | arr2[i];

	vector<string> answer;
	for (int i = 0; i<n; i++) {
		string str = "";
		int num = tmp[i];
		for (int j = 0; j<n; j++) {
			int temp = num & 1;
			if (temp == 1)
				str += "#";
			else
				str += " ";
			num = num >> 1;
		}
		reverse(str.begin(), str.end());
		answer.push_back(str);
	}
	return answer;
}

int main() {
	int n = 5;
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };
	vector<string> tmp = solution(n, arr1, arr2);
	return 0;
}