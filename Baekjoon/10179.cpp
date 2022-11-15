#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        double p;
        cin >> p;

        cout.precision(2);
        cout << fixed << '$' << p * 0.8 << '\n';
    }
    return 0;
}