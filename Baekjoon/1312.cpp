#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    if(a >= b) a %= b;
    int div;

    for(int i=0; i<n; i++) {
        a *= 10;
        div = a / b;
        a %= b;
    }
    cout << div << '\n';
    return 0;
}