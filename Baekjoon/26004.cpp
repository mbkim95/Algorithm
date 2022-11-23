#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
    int n, ans = 987654321;
    string str;
    set<char> s = {'H', 'I', 'A', 'R', 'C'};
    map<char, int> m;

    cin >> n;
    cin >> str;
    for(char c : str) ++m[c];

    bool canMake = true;
    for(char c : s) {
        if(m[c] == 0) {
            canMake = false;
            break;
        }
    }

    if(!canMake) ans = 0;
    else {
        for(auto it : m) {
            if(s.count(it.first) > 0) ans = min(ans, it.second);
        }
    }
    cout << ans << '\n';
    return 0;
}