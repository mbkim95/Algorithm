#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<pair<pair<int, int>, int>> build;

// 해당 위치에 구조물이 설치되어있는지 확인
bool is_builded(int x, int y, int a) {
	if (build.find({ {x, y}, a }) != build.end()) return true;
	return false;
}

// 첫 번째 규칙
bool rule1(int x, int y) {
	if (y == 0 || is_builded(x, y, 1) || is_builded(x - 1, y, 1) || is_builded(x, y - 1, 0)) return true;
	return false;
}

// 두 번째 규칙
bool rule2(int x, int y) {
	if (is_builded(x, y - 1, 0) || is_builded(x + 1, y - 1, 0) || (is_builded(x - 1, y, 1) && is_builded(x + 1, y, 1))) return true;
	return false;
}

// 설치된 모든 구조물이 규칙을 만족시키는지 확인
bool checkAll() {
	for (auto it : build) {
		int x = it.first.first, y = it.first.second, a = it.second;
		if (a == 0) {
			if (!rule1(x, y)) return false;
		}
		else {
			if (!rule2(x, y)) return false;
		}
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (vector<int> v : build_frame) {
		int x = v[0], y = v[1], a = v[2], b = v[3];
		if (b == 1) { // 구조물 설치
			build.insert({ {x, y}, a });
			if (!checkAll()) build.erase({ {x, y}, a }); // 규칙을 만족시키지 않으면 제거
		}
		else { // 구조물 삭제
			build.erase({ {x, y}, a });
			if (!checkAll()) build.insert({ {x, y}, a }); // 규칙을 만족시키지 않으면 다시 추가
		}
	}
	for (auto it : build) {
		answer.push_back({ it.first.first, it.first.second, it.second });
	}
	sort(answer.begin(), answer.end());
	return answer;
}