#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    long long a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << ((a * 2 <= b && b % a == 0) ? 1 : 0) << '\n';
    }
    return 0;
}