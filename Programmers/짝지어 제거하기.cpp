#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string str)
{
    int answer = 0;
	stack<char> s;
	for (char c : str) {
		if (s.empty()) s.push(c);
		else if (s.top() == c) s.pop();
		else s.push(c);
	}
	if (s.empty()) answer = 1;
    return answer;
}