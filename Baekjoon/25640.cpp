#include <iostream>
using namespace std;

int main() { 
    string m, f;
    cin >> m;
    int n, ans = 0;
    cin >> n;
    while(n--) {
        cin >> f;
        if(m == f) ans++;
    }
    cout << ans << '\n';
    return 0;
}