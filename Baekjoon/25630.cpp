#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    string str;
    cin >> n;
    cin >> str;
    int s = 0, e = n-1;

    while(s < e) {
        if(str[s] != str[e]) ans++;
        s++;
        e--;
    }
    cout << ans << '\n';
    return 0;
}