#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int chk[60 * 60 * 24 * 1000 + 1];

struct Time {
	int h, m, s, ss;
};

// 처리 시간을 millisec로 변환해주는 함수
int get_millisec(string millisec) {
	int ret = 0;
	if (millisec.find('.') == string::npos) return stoi(millisec.substr(0, 1)) * 1000;
	for (int i = 0; i < millisec.length(); i++)
		if (millisec[i] == '.') {
			ret += stoi(millisec.substr(0, 1)) * 1000;
			ret += stoi(millisec.substr(i + 1));
			break;
		}
	return ret;
}

// 처리가 끝난 시간을 int로 변환해주는 함수
Time parse_lines(string str) {
	int h = stoi(str.substr(11, 2));
	int m = stoi(str.substr(14, 2));
	int s = stoi(str.substr(17, 2));
	int ss = stoi(str.substr(20, 3));
	return { h, m, s, ss };
}

int solution(vector<string> lines) {
	int answer = 0;
	for (string str : lines) {
		// 시간을 millisec 단위로 변경
		Time t = parse_lines(str);
		int h = t.h * 60 * 60 * 1000;
		int m = t.m * 60 * 1000;
		int s = t.s * 1000;
		int ss = t.ss;
		int pt = get_millisec(str.substr(24));

		// 끝나는 시간을 millisec로 구한다
		int last = h + m + s + ss;
		// 시작한 시간을 구한다.
		int first = last - pt + 1;
		// 초 단위 답을 구하기 위해 999를 더해준다
		last += 999;
		// 0보다 작으면 9월 14일이 되므로 9월 15일 00시 00분 00초로 변경
		if (first < 0) first = 0;
		// 최대 범위를 벗어나면 최대값으로 변경
		if (last > 24 * 60 * 60 * 1000) last = 24 * 60 * 60 * 1000;

		// 범위 내 값 증가
		for (int i = first; i <= last; i++)
			chk[i]++;
	}

	for (int i = 0; i <= 24 * 60 * 60 * 1000; i++)
		answer = max(answer, chk[i]);
	return answer;
}