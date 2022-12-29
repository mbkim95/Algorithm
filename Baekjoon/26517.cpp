#include <iostream>
using namespace std;

int main() {
    long long k, a, b, c, d;
    cin >> k;
    cin >> a >> b >> c >> d;
    if(a * k + b == c * k + d) cout << "Yes " << a * k + b << '\n';
    else cout << "No\n";
    return 0;
}