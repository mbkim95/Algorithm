#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;

	stack<int> s;

	bool is_correct = true;
	for (char c : str) {
		// 괄호가 잘못된 경우
		if (!is_correct) break;
		// 열린 괄호일 때
		if (c == '(' || c == '[') {
			// 숫자로 변환해서 스택에 저장
			int tmp = c == '(' ? -1 : -2;
			s.push(tmp);
		}
		else {
			// 스택이 비었다는 것은 괄호 짝이 안맞는다는 의미
			if (s.empty()) {
				is_correct = false;
				break;
			}
			// 스택에 들어있는 숫자 저장 변수
			int num = 0;
			// 괄호가 제대로 닫히는지 체크용 변수
			bool is_closed = false;
			while (!s.empty()) {
				// 열린 괄호가 나오는 경우 반복문을 빠져나온다
				if (s.top() < 0) {
					// 짝이 안맞는 괄호인 경우
					if(!((c == ')' && s.top() == -1) || (c == ']' && s.top() == -2))) is_correct = false;
					// 괄호가 닫혔다
					is_closed = true;					
					s.pop(); // 스택에 들어있던 열린 괄호를 pop
					break;
				}
				num += (s.top());
				s.pop();
			}
			// 괄호가 안닫히고 반복문을 빠져나오면 에러
			if (!is_closed) is_correct = false;
			// 괄호가 잘못되면 반복문을 빠져나온다
			if (!is_correct) break;			
			if (c == ')') {
				// 스택에서 숫자가 나오지 않으면 2를 넣어준다
				if (num == 0) s.push(2);
				// 숫자를 찾았으면 2배 해준다
				else s.push(num * 2);
			}
			else if (c == ']') {
				// 스택에서 숫자가 나오지 않으면 3을 넣어준다
				if (num == 0) s.push(3);
				// 숫자를 찾았으면 3배 해준다
				else s.push(num * 3);
			}
		}
	}
	int ans = 0;
	// 스택에 남은 숫자를 모두 더해준다
	while (!s.empty()) {
		if (s.top() < 0) {
			is_correct = false;
			break;
		}
		ans += s.top();
		s.pop();
	}
	if (is_correct) cout << ans << '\n';
	else cout << "0\n";
	return 0;
}