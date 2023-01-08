#include <iostream>
using namespace std;

int n, t, e;

int main() {
    string s;
    cin >> n;
    cin >> s;
    for(char c : s)  {
        if(c == 'e') e++;
        else t++;
    }
    if(t == e) cout << "yee\n";
    else if(t > e) cout << 2 << '\n';
    else cout << "e" << '\n';
    return 0;
}