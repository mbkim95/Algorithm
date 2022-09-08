#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans = "int";

    while(true) {
        if(n == 0) break;
        ans = "long " + ans;
        n-=4;
    }
    cout << ans << '\n';
    return 0;
}