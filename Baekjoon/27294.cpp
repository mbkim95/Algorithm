#include <iostream>
using namespace std;

int main() {
    int t, s;
    cin >> t >> s;
    if(s == 1 || !(12 <= t && t <= 16)) cout << "280\n";
    else cout << "320\n";
    return 0;
}