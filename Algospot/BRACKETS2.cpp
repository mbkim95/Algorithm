#include <iostream>
#include <stack>
#include <string>
using namespace std;	

bool isMatched(const string& formula) {
	const string opening("({["), closing(")}]");

	stack<char> stack;

	for (int i = 0; i < formula.size(); i++) {
		if (opening.find(formula[i]) != -1)
			stack.push(formula[i]);
		else {
			if (stack.empty())
				return false;
			if (opening.find(stack.top()) != closing.find(formula[i]))
				return false;
			stack.pop();
		}		
	}
	return stack.empty();
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		string formula;
		cin >> formula;
		isMatched(formula) ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}