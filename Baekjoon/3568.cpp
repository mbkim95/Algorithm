#include <iostream>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);
	stringstream ss(str);

	string type;
	string variable;

	ss >> type;
	while (ss >> variable) {
		cout << type;
		// 잘라진 문자열의 맨 끝은 , 또는 ; 이므로 variable.size()-2부터 시작
		for (int i = variable.size() - 2; i >= 0; i--) {
			char c = variable[i];
			if (c == ']') {
				cout << "[]";
				i--;
			}
			else if (c == '&' || c == '*')
				cout << c;
			else {
				// 변수 이름인 경우 뛰어쓰기하고 제대로된 순서로 출력
				cout << ' ';
				for (int j = 0; j <= i; j++)
					cout << variable[j];
				cout << ";\n";
				break;
			}
		}
	}
	
	return 0;
}