#include <iostream>
using namespace std;

int main() {
    int n, s = 0, t = 0, idx = 0;
    string str;
    cin >> n;
    cin >> str;
    for (char c : str) {
        if (c == 's') s++;
        else t++;
    }
    while (s != t) {
        if (str[idx] == 's') s--;
        else t--;
        idx++;
    }
    cout << str.substr(idx, str.length() - idx) << '\n';
    return 0;
}