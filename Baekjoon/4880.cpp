#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while(true) {
        cin >> a >> b >>c;
        if(a == 0 && b == 0 && c == 0) break;
        if(a + c == 2 * b) cout << "AP " << c + b - a << '\n';
        else cout << "GP " << c * b / a << '\n';
    }
    return 0;
}