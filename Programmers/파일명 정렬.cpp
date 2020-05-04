#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// HEAD와 TAIL 추출
pair<string, int> parse_head_tail(string file) {
	pair<string, int> ret;
	int idx = 0;
    // HEAD 추출하기 위해 탐색
	for (char c : file) {
		if ('0' <= c && c <= '9') break;
		idx++;
	}
	int num = 0;
    // TAIL의 값을 추출하기 위해 탐색
	for (int i = idx; i < file.length(); i++) {
		if (!('0' <= file[i] && file[i] <= '9')) break;
		num = num * 10 + (file[i] - '0');
	}
    // HEAD, TAIL 리턴
	return { file.substr(0, idx), num };
}

bool cmp(const string& a, const string& b) {
	pair<string, int> file_a = parse_head_tail(a);
	pair<string, int> file_b = parse_head_tail(b);
    // 대문자로 변환
	for (char& c : file_a.first) c = toupper(c);
	for (char& c : file_b.first) c = toupper(c);
    // HEAD가 일치하면 TAIL을 비교해서 정렬
	if (file_a.first == file_b.first) return file_a.second < file_b.second;
    // HEAD로 정렬
	return file_a.first < file_b.first;
}

vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), cmp);
	return files;
}