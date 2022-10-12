#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    if(a < 0) cout << -a * c + d + b * e << '\n';
    else cout << (b - a) * e<< '\n';
    return 0;
}