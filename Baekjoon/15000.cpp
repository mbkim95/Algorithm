#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char c : s) cout << (char)(c - ('a' - 'A'));
    cout << '\n';
    return 0;
}