#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    if(s[0] - '0' + s[4] - '0' == s[8] - '0') cout << "YES\n";
    else cout << "NO\n";
    return 0;
}