#include <iostream>
#include <string>
using namespace std;

int main() {
    while(true) {
        int cnt = 0;
        char c;
        string s;
        cin >> c;
        getline(cin, s);
        if(c == '#') break;

        for(char ch : s) if(tolower(c) == tolower(ch)) cnt++;
        cout << c << ' ' << cnt << '\n';
    }
    return 0;
}