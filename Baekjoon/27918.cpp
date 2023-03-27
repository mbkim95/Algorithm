#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d = 0, p = 0;
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        if(abs(d-p) == 2) continue;

        if(c == 'D') d++;
        else p++;
    }
    cout << d << ':' << p << '\n';
    return 0;
}