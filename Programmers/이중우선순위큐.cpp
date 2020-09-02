#include <string> 
#include <vector> 
#include <list> 
using namespace std;

vector<int> solution(vector<string> operations) {
	list<int> list;
	for (string str : operations) {
		if (str[0] == 'I') list.push_back(stoi(str.substr(2, str.length() - 2)));
		else {
			list.sort();
			if (list.empty()) continue;
			else if (str[2] == '1') list.pop_back();
			else list.pop_front();
		}
	}
	if (list.empty()) return { 0, 0 };
	list.sort();
	vector<int> answer = { list.back(), list.front() };
	return answer;
}