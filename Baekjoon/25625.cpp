#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y;
    cin >> x >> y;

    if(x < y) cout << y-x << '\n';
    else if(x > y) cout << x+y << '\n';
    else cout << x << '\n';
    return 0;
}