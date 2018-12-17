#include <iostream>
#include <string>
using namespace std;

int arr[26];

int main() {
	string str;	
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a') {
			arr[str[i] - 'a']++;
		}
		else {			
			arr[str[i] - 'A']++;
		}
	}

	int idx = 0;
	int cnt = 0;
	int max = arr[0];
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			idx = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == max)
			cnt++;
	}

	if (cnt >= 2) {
		cout << '?' << endl;
	}
	else {
		cout << (char)(idx + 'A') << endl;
	}
}