#include <iostream>
using namespace std;

int main() {
    float t;

    cin >> t;
    while(true) {
        float prev = t;
        cin >> t;

        if(t == 999) break;

        cout.precision(2);
        cout << fixed << t - prev << '\n';
    }
    return 0;
}