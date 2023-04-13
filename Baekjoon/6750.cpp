#include <iostream>
#include <set>
using namespace std;


int main() {
    string str;
    cin >> str;
    set<char> s = { 'I', 'O', 'S', 'H', 'Z', 'X', 'N'};
    bool good = true;

    for(char c : str) {
        if(s.find(c) == s.end()) {
            good = false;
            break;
        }
    }

    if(good) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}